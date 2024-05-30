#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("This is the child process.\n");
        _exit(0);
    } else {
        wait(NULL);
        printf("This is the parent process. Child has terminated.\n");
    }

    return 0;
}