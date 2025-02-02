#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5000
#define MAX_MSG_SIZE 1024

void *client_handler(void *arg) {
    int client_fd = *((int *)arg);
    char buffer[MAX_MSG_SIZE];

    // Receive message from client
    int n = read(client_fd, buffer, MAX_MSG_SIZE);
    if (n <= 0) {
        perror("Read error");
        close(client_fd);
        return NULL;
    }
    buffer[n] = '\0';

    // Reverse the string
    int len = strlen(buffer);
    for (int i = 0; i < len / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[len - i - 1];
        buffer[len - i - 1] = temp;
    }

    // Send reversed string back to client
    write(client_fd, buffer, strlen(buffer));

    close(client_fd);
    return NULL;
}

int main() {
    int sockfd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("TCP Server is running on port %d...\n", PORT);

    // Accept incoming connections and handle them
    while (1) {
        if ((client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create thread to handle client
        if (pthread_create(&tid, NULL, client_handler, &client_fd) != 0) {
            perror("Thread creation failed");
            close(client_fd);
        }

        pthread_detach(tid); // Detach thread
    }

    close(sockfd);
    return 0;
}