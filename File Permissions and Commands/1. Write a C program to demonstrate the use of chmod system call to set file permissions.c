#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *file = "example.txt";

    // Set file permissions to read, write for owner; read for group and others
    if (chmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        perror("Error changing file permissions");
    }

    return 0;
}