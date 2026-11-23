#include <iostream>
using namespace std;

// GLOBAL VARIABLE: accessible everywhere
int globalCounter = 100;

void displayGlobal() {
    cout << "Inside displayGlobal: globalCounter = " << globalCounter << endl;
    // Uncommenting the line below causes a compile error (localCounter belongs to main):
    // cout << localCounter;
}

void modifyGlobal() {
    globalCounter = 500;
    cout << "Inside modifyGlobal: globalCounter changed to " << globalCounter << endl;
}

void localDemo() {
    // Local variable with the same name SHADOWS the global variable
    int globalCounter = 999;
    cout << "Inside localDemo: globalCounter = " << globalCounter << endl;
}

int main() {
    int localCounter = 50;

    cout << "In main: globalCounter = " << globalCounter << endl;
    cout << "In main: localCounter = " << localCounter << endl;

    displayGlobal();
    modifyGlobal();
    localDemo();

    cout << "Back in main: globalCounter = " << globalCounter << endl;

    return 0;
}