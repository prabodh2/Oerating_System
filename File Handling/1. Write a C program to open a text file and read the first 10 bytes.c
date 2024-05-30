#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[11];
    if (fread(buffer, 1, 10, file) == 10) {
        buffer[10] = '\0';
        printf("First 10 bytes: %s\n", buffer);
    } else {
        perror("Error reading file");
    }

    fclose(file);
    return 0;
}