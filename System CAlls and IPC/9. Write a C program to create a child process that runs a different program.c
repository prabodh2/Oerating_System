#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        execlp("/bin/ls", "ls", NULL);
        perror("execlp");
        return 1;
    } else {
        wait(NULL);
        printf("Child process executed ls command.\n");
    }

    return 0;
}