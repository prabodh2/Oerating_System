#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    signal(SIGINT, handle_signal);

    while (1) {
        printf("Running... Press Ctrl+C to send SIGINT.\n");
        sleep(1);
    }

    return 0;
}