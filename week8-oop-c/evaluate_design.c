#include <stdio.h>

// THE BAD DESIGN (Violation of Encapsulation)
struct BadBankAccount {
    double balance;
};

// THE GOOD DESIGN (Encapsulation via functions)
struct GoodBankAccount {
    double balance;
};

void goodDeposit(struct GoodBankAccount *acc, double amount) {
    if (amount > 0) {
        acc->balance += amount;
    }
}

int main() {
    printf("--- Testing BAD Design ---\n");
    struct BadBankAccount badAccount;
    badAccount.balance = 100.0;

    // Direct access allows invalid negative balance
    badAccount.balance = -5000.00;
    printf("Bad Account Balance: %.2f\n", badAccount.balance);

    printf("\n--- Testing GOOD Design ---\n");
    struct GoodBankAccount goodAccount;
    goodAccount.balance = 100.0;

    goodDeposit(&goodAccount, 500.00);
    printf("Good Account Balance: %.2f\n", goodAccount.balance);

    return 0;
}