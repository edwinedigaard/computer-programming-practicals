#include <stdio.h>

int main() {
    int originalValue = 100;

    // Two pointers pointing to the exact same memory address (simulating aliases)
    int *ptr1 = &originalValue;
    int *ptr2 = &originalValue;

    printf("--- Initial State ---\n");
    printf("originalValue: %d\n", originalValue);
    printf("Value via ptr1: %d\n", *ptr1);

    // Modification 1: Changing value via ptr1 updates originalValue and *ptr2
    *ptr1 = 200;
    printf("\n--- After setting *ptr1 = 200 ---\n");
    printf("originalValue: %d\n", originalValue);
    printf("Value via ptr2: %d\n", *ptr2);

    // Modification 2: Changing value via ptr2 updates originalValue and *ptr1
    *ptr2 = 300;
    printf("\n--- After setting *ptr2 = 300 ---\n");
    printf("originalValue: %d\n", originalValue);
    printf("Value via ptr1: %d\n", *ptr1);

    // Modification 3: Reassigning ptr1 to point to a different variable
    int anotherValue = 500;
    ptr1 = &anotherValue;
    printf("\n--- After pointing ptr1 to anotherValue ---\n");
    printf("originalValue: %d\n", originalValue); // Remains 300
    printf("Value via ptr1: %d\n", *ptr1);        // Prints 500

    return 0;
}