#include <stdio.h>

int main(int argc, char *argv[]) {
    // Expecting 3 arguments: program name, source file, destination file
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *dest = fopen(argv[2], "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src); // Clean up already-opened file before exiting
        return 1;
    }

    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("Successfully copied '%s' to '%s'.\n", argv[1], argv[2]);

    fclose(src);
    fclose(dest);
    return 0;
}