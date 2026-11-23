#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Enter filename to open (try 'missing.txt' first, then 'notes.txt'): ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // perror prints your custom message followed by the OS error reason
        perror("File open failed");
        printf("Error code (errno): %d (%s)\n", errno, strerror(errno));
        return 1;
    }

    printf("\nFile opened successfully! Reading lines:\n");
    char buffer[256];
    int lineNum = 1;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%d: %s", lineNum++, buffer);
    }

    fclose(fp);
    return 0;
}