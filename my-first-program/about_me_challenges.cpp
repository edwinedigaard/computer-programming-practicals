#include <iostream>
#include <string>
using namespace std;

int main() {
    // Original 6 variables
    string name;
    string course;
    string hobby;
    string reason;
    string expectation;
    string definition;

    // CHALLENGE 1: 2 additional variables
    string favouriteFood;
    string dreamJob;

    // CHALLENGE 4: Decorative formatting
    cout << "**************************************************" << endl;
    cout << "*       WELCOME TO YOUR FIRST C++ PROGRAM!       *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;

    // Question 1: Name
    cout << "1. What is your name? ";
    getline(cin, name);

    // CHALLENGE 2: Validation for empty name
    if (name == "") {
        cout << "You didn't enter a name!" << endl;
    }

    // Question 2: Course
    cout << "2. What course are you doing? (BBIT/BCS): ";
    getline(cin, course);

    // Question 3: Hobby
    cout << "3. What is your hobby? ";
    getline(cin, hobby);

    // Question 4: Reason
    cout << "4. Why did you choose this course? ";
    getline(cin, reason);

    // Question 5: Expectation
    cout << "5. What do you expect to learn in programming? ";
    getline(cin, expectation);

    // Question 6: Definition
    cout << "6. In your own words, what is programming? ";
    getline(cin, definition);

    // CHALLENGE 1: Ask the 2 additional questions
    cout << "7. What is your favourite food? ";
    getline(cin, favouriteFood);

    cout << "8. What is your dream job? ";
    getline(cin, dreamJob);

    // CHALLENGE 4: Formatted summary output
    cout << endl;
    cout << "**************************************************" << endl;
    cout << "*              YOUR PROFILE SUMMARY              *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;

    cout << "  Name:           " << name << endl;
    cout << "  Course:         " << course << endl;
    cout << "  Hobby:          " << hobby << endl;
    cout << "  Reason:         " << reason << endl;
    cout << "  Expectation:    " << expectation << endl;
    cout << "  Programming is: " << definition << endl;
    cout << "  Favourite Food: " << favouriteFood << endl;
    cout << "  Dream Job:      " << dreamJob << endl;
    cout << endl;

    // CHALLENGE 3: Personalized final message
    cout << "--------------------------------------------------" << endl;
    cout << "Great job, " << name << "! You are on your way to becoming a programmer!" << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}