#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.csv"

struct Student {
    char name[50];
    int score;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen(FILENAME, "a"); // "a" appends without erasing existing records
    if (fp == NULL) {
        perror("Could not open database file");
        return;
    }

    printf("Enter student name: ");
    getchar(); // Clear leftover newline from menu scanf
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter student score (0-100): ");
    scanf("%d", &s.score);

    if (s.score < 0 || s.score > 100) {
        printf("Invalid score! Record not saved.\n");
        fclose(fp);
        return;
    }

    fprintf(fp, "%s,%d\n", s.name, s.score);
    fclose(fp);
    printf("Saved %s (%d) to %s.\n", s.name, s.score, FILENAME);
}

void viewStudents() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No records found yet (file does not exist).\n");
        return;
    }

    char line[100];
    int count = 0;
    int total = 0;

    printf("\n--- Saved Student Records ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        char name[50];
        int score;
        // Parse "Name,Score" separated by comma
        if (sscanf(line, "%49[^,],%d", name, &score) == 2) {
            count++;
            total += score;
            printf("%d. %-20s | Score: %d\n", count, name, score);
        }
    }

    if (count > 0) {
        printf("-----------------------------\n");
        printf("Total Students: %d | Class Average: %.2f\n", count, (double)total / count);
    } else {
        printf("Database is empty.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORDS SYSTEM =====\n");
        printf("1. Add Student Record\n");
        printf("2. View All Records\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                printf("Exiting program. Data remains saved in %s.\n", FILENAME);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}