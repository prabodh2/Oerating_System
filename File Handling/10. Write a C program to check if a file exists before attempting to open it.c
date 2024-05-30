#include <stdio.h>

int main() {
    const char *filename = "example.txt";
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        printf("File exists\n");
        fclose(file);
    } else {
        printf("File does not exist\n");
    }

    return 0;
}
