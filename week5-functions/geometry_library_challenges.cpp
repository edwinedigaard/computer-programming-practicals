#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159;

// Helper for Challenge 3: Reject negative input cleanly
double getPositiveInput(string prompt) {
    double val;
    do {
        cout << prompt;
        cin >> val;
        if (val < 0) {
            cout << "Invalid! Value cannot be negative. Try again." << endl;
        }
    } while (val < 0);
    return val;
}

double areaOfCircle(double radius) {
    return PI * radius * radius;
}

double areaOfRectangle(double length, double width) {
    return length * width;
}

double areaOfTriangle(double base, double height) {
    return 0.5 * base * height;
}

// Challenge 1: Area of Square
double areaOfSquare(double side) {
    return side * side;
}

// Challenge 2: Perimeter of Rectangle
double perimeterOfRectangle(double length, double width) {
    return 2 * (length + width);
}

void displayMenu() {
    cout << "\n===== GEOMETRY CALCULATOR (CHALLENGES) =====" << endl;
    cout << "1. Area of Circle" << endl;
    cout << "2. Area & Perimeter of Rectangle" << endl;
    cout << "3. Area of Triangle" << endl;
    cout << "4. Area of Square" << endl;
    cout << "5. Calculate All" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double radius, length, width, base, height, side;

    do {
        displayMenu();
        cin >> choice;
        cout << fixed << setprecision(2);

        switch (choice) {
            case 1:
                radius = getPositiveInput("Enter radius: ");
                cout << "Area of circle: " << areaOfCircle(radius) << endl;
                break;
            case 2:
                length = getPositiveInput("Enter length: ");
                width = getPositiveInput("Enter width: ");
                cout << "Area of rectangle: " << areaOfRectangle(length, width) << endl;
                cout << "Perimeter of rectangle: " << perimeterOfRectangle(length, width) << endl;
                break;
            case 3:
                base = getPositiveInput("Enter base: ");
                height = getPositiveInput("Enter height: ");
                cout << "Area of triangle: " << areaOfTriangle(base, height) << endl;
                break;
            case 4:
                side = getPositiveInput("Enter side: ");
                cout << "Area of square: " << areaOfSquare(side) << endl;
                break;
            case 5: // Challenge 4: Calculate All
                radius = getPositiveInput("Enter circle radius: ");
                length = getPositiveInput("Enter rectangle length: ");
                width = getPositiveInput("Enter rectangle width: ");
                base = getPositiveInput("Enter triangle base: ");
                height = getPositiveInput("Enter triangle height: ");
                side = getPositiveInput("Enter square side: ");

                cout << "\n--- ALL RESULTS ---" << endl;
                cout << "Circle Area:         " << areaOfCircle(radius) << endl;
                cout << "Rectangle Area:      " << areaOfRectangle(length, width) << endl;
                cout << "Rectangle Perimeter: " << perimeterOfRectangle(length, width) << endl;
                cout << "Triangle Area:       " << areaOfTriangle(base, height) << endl;
                cout << "Square Area:         " << areaOfSquare(side) << endl;
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}