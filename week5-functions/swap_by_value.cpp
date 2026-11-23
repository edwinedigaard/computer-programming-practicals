#include <iostream>
using namespace std;

// Pass-by-value: receives COPIES of x and y
void swapByValue(int a, int b) {
    cout << "  Inside swapByValue - Before swap: a = " << a << ", b = " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "  Inside swapByValue - After swap:  a = " << a << ", b = " << b << endl;
}

// Step 6 Challenge - Pass-by-reference: receives ALIASES (&) to original x and y
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Before calling swapByValue:" << endl;
    cout << "  x = " << x << ", y = " << y << endl;

    swapByValue(x, y);

    cout << "After calling swapByValue:" << endl;
    cout << "  x = " << x << ", y = " << y << endl;
    cout << "\nExplanation: The function received COPIES of x and y." << endl;
    cout << "Changes made inside the function do not affect the originals." << endl;

    // Step 6 Challenge: Test pass-by-reference
    cout << "\n--- Step 6 Challenge: Pass-by-Reference ---" << endl;
    swapByReference(x, y);
    cout << "After calling swapByReference:" << endl;
    cout << "  x = " << x << ", y = " << y << endl;

    return 0;
}