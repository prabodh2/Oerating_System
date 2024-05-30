#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Caught SIGINT signal (%d)\n", sig);
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Running... Press Ctrl+C to send SIGINT.\n");
        sleep(1);
    }

    return 0;
}