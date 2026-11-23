#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declaration (opaque type)
typedef struct Account Account;

// Public API prototypes
Account* createAccount(const char *owner, double initialBalance);
void depositAccount(Account *acc, double amount);
void printAccount(const Account *acc);
void destroyAccount(Account *acc);

// --- Hidden Implementation Details ---
struct Account {
    char owner[50];
    double balance;
};

Account* createAccount(const char *owner, double initialBalance) {
    Account *acc = (Account*)malloc(sizeof(Account));
    if (acc != NULL) {
        strcpy(acc->owner, owner);
        acc->balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }
    return acc;
}

void depositAccount(Account *acc, double amount) {
    if (acc != NULL && amount > 0) {
        acc->balance += amount;
        printf("Deposited $%.2f\n", amount);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void printAccount(const Account *acc) {
    if (acc != NULL) {
        printf("Owner: %s | Balance: $%.2f\n", acc->owner, acc->balance);
    }
}

void destroyAccount(Account *acc) {
    free(acc);
}

int main() {
    Account *myAcc = createAccount("Jane Doe", 1000.00);

    printAccount(myAcc);
    depositAccount(myAcc, 250.00);
    printAccount(myAcc);

    destroyAccount(myAcc);
    myAcc = NULL;

    return 0;
}