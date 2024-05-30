#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("example.txt", "r");
    if (file != NULL) {
        printf("Opened in read mode\n");
        fclose(file);
    }

    file = fopen("example.txt", "w");
    if (file != NULL) {
        printf("Opened in write mode\n");
        fclose(file);
    }

    file = fopen("example.txt", "a");
    if (file != NULL) {
        printf("Opened in append mode\n");
        fclose(file);
    }

    file = fopen("example.txt", "r+");
    if (file != NULL) {
        printf("Opened in read/write mode\n");
        fclose(file);
    }

    file = fopen("example.txt", "w+");
    if (file != NULL) {
        printf("Opened in write/read mode\n");
        fclose(file);
    }

    return 0;
}