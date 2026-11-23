#include <stdio.h>

int main() {
    FILE *filePtr;

    // 1. WRITE TO FILE ("w" creates a new file or overwrites an existing one)
    filePtr = fopen("notes.txt", "w");
    if (filePtr == NULL) {
        printf("Error: Could not open notes.txt for writing.\n");
        return 1;
    }

    fprintf(filePtr, "Week 10 Practical: File Handling in C\n");
    fprintf(filePtr, "1. Always check if fopen() returns NULL.\n");
    fprintf(filePtr, "2. Always call fclose() when finished.\n");
    fclose(filePtr);
    printf("Data successfully written to notes.txt.\n\n");

    // 2. READ FROM FILE ("r" opens an existing file for reading)
    filePtr = fopen("notes.txt", "r");
    if (filePtr == NULL) {
        printf("Error: Could not open notes.txt for reading.\n");
        return 1;
    }

    char line[256];
    printf("--- Contents of notes.txt ---\n");
    while (fgets(line, sizeof(line), filePtr) != NULL) {
        printf("%s", line);
    }

    fclose(filePtr);
    return 0;
}