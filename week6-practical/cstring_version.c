#include <stdio.h>
#include <string.h> // Required for strlen, strcpy, strcspn

int main() {
    char name[50];

    printf("Enter your name: ");
    // fgets safely reads a full line including spaces
    fgets(name, 50, stdin);

    // Strip the trailing '\n' character added by fgets
    name[strcspn(name, "\n")] = '\0';

    printf("Name: %s\n", name);
    printf("Length: %zu\n", strlen(name)); // %zu (or %lu) formats size_t
    printf("First character: %c\n", name[0]);

    // Copy C-string to another char array
    char copy[50];
    strcpy(copy, name);
    printf("Copy: %s\n", copy);

    return 0;
}