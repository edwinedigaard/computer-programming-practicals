#include <stdio.h>

int main() {
    printf("==================================================\n");
    printf("          MULTIPLICATION TABLE (1 to 10)\n");
    printf("==================================================\n\n");

    // Outer loop: rows 1 to 10
    for (int i = 1; i <= 10; i++) {
        // Inner loop: columns 1 to 10
        for (int j = 1; j <= 10; j++) {
            // %5d prints each number right-aligned in a 5-character width
            printf("%5d", i * j);
        }
        printf("\n");
    }

    printf("==================================================\n");

    return 0;
}