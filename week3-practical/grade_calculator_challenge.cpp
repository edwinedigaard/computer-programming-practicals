#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int numStudents;
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    cout << "How many students? ";
    cin >> numStudents;

    for (int i = 1; i <= numStudents; i++) {
        string studentName;
        double score;
        char grade;
        char modifier = ' ';

        cout << "\n--- Student " << i << " ---" << endl;
        cout << "Enter student name: ";
        cin.ignore(); // Clear leftover newline from cin >>
        getline(cin, studentName);

        cout << "Enter percentage score (0-100): ";
        cin >> score;

        if (score < 0 || score > 100) {
            cout << "Invalid score! Skipping student." << endl;
            continue;
        }

        if (score >= 90) { grade = 'A'; countA++; }
        else if (score >= 80) { grade = 'B'; countB++; }
        else if (score >= 70) { grade = 'C'; countC++; }
        else if (score >= 60) { grade = 'D'; countD++; }
        else { grade = 'F'; countF++; }

        if (grade != 'F') {
            int lastDigit = (int)score % 10;
            if (grade == 'A') {
                if (score >= 97) modifier = '+';
                else if (score < 93) modifier = '-';
            } else {
                if (lastDigit >= 7) modifier = '+';
                else if (lastDigit <= 3) modifier = '-';
            }
        }

        cout << studentName << " -> Score: " << fixed << setprecision(1) << score << "%, Grade: " << grade;
        if (modifier != ' ') cout << modifier;
        cout << endl;
    }

    cout << "\n===== CLASS GRADE SUMMARY =====" << endl;
    cout << "A's: " << countA << endl;
    cout << "B's: " << countB << endl;
    cout << "C's: " << countC << endl;
    cout << "D's: " << countD << endl;
    cout << "F's: " << countF << endl;

    return 0;
}