#include <stdio.h>
#include <stdlib.h>

void fixLeak() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *ptr = 42;
    printf("Inside fixed function. Value: %d\n", *ptr);

    // Free heap memory and prevent dangling pointer
    free(ptr);
    ptr = NULL;

    printf("Memory has been successfully freed.\n");
}

int main() {
    printf("--- Testing the Fix ---\n");
    fixLeak();
    return 0;
}