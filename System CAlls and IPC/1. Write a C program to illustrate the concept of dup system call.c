#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    int new_fd = dup(fd);
    if (new_fd < 0) {
        perror("dup");
        close(fd);
        return 1;
    }
    
    write(fd, "Hello, ", 7);
    write(new_fd, "World!\n", 7);
    
    close(fd);
    close(new_fd);
    
    return 0;
}