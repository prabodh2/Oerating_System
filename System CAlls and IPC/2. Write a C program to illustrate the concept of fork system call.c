#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process.\n");
    } else {
        printf("This is the parent process.\n");
    }

    return 0;
}

