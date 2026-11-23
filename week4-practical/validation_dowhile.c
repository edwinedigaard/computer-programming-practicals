#include <stdio.h>

int main() {
    int number = 0;

    // Body runs FIRST, then condition is checked
    do {
        printf("Enter a positive number: ");
        scanf("%d", &number);

        if (number <= 0) {
            printf("Invalid! ");
        }
    } while (number <= 0);

    printf("You entered: %d\n", number);

    return 0;
}