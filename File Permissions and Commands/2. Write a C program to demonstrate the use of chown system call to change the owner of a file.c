#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    const char *file = "example.txt";
    uid_t owner = 1000; // Change to appropriate user ID
    gid_t group = 1000; // Change to appropriate group ID

    if (chown(file, owner, group) == 0) {
        printf("File owner changed successfully.\n");
    } else {
        perror("Error changing file owner");
    }

    return 0;
}