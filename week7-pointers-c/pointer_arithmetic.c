#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // Array name points to the first element

    printf("Array elements accessed via pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("Value: %d\n", *ptr);
        ptr++; // Moves pointer forward by 1 int (4 bytes)
    }

    // Reset the pointer back to the start of the array
    ptr = numbers;

    printf("\nAccessing using offset arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("Index %d has value: %d\n", i, *(ptr + i));
    }

    return 0;
}