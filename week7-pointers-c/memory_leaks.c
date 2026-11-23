#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

void createLeak() {
    int *ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *ptr = 42;
    printf("Inside function. The value is: %d\n", *ptr);
    printf("Memory allocated at address: %p\n", (void*)ptr);
    // LEAK: Function ends without calling free(ptr)
}

int main() {
    printf("Calling function that leaks memory...\n");
    createLeak();
    printf("Function finished. The memory is now leaked.\n");
    return 0;
}