#include <stdio.h>

int main() {
    FILE *file = fopen("hello.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    fprintf(file, "Hello, World!\n");

    fclose(file);
    return 0;
}
