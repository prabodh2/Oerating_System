#include <stdio.h>

int main() {
    FILE *file = fopen("newfile.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    printf("File created and opened successfully.\n");

    fclose(file);
    return 0;
}