#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *file = "example.txt";
    struct stat fileStat;

    if (stat(file, &fileStat) == 0) {
        printf("File size: %ld bytes\n", fileStat.st_size);
        printf("Number of links: %lu\n", fileStat.st_nlink);
        printf("File inode: %lu\n", fileStat.st_ino);
        printf("File permissions: %o\n", fileStat.st_mode);
        printf("Last access time: %ld\n", fileStat.st_atime);
    } else {
        perror("Error getting file status");
    }

    return 0;
}
