```c
#include <stdio.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account *account) {
    printf("\nEnter Account Number: ");
    scanf("%d", &account->accountNumber);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", account->name);

    printf("Enter Initial Deposit: ");
    scanf("%f", &account->balance);

    printf("\nAccount created successfully!\n");
}

void depositMoney(struct Account *account) {
    float amount;

    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        account->balance += amount;
        printf("Amount deposited successfully!\n");
        printf("Current Balance: %.2f\n", account->balance);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdrawMoney(struct Account *account) {
    float amount;

    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    } else if (amount > account->balance) {
        printf("Insufficient balance!\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful!\n");
        printf("Current Balance: %.2f\n", account->balance);
    }
}

void displayAccount(struct Account account) {
    printf("\n===== Account Details =====\n");
    printf("Account Number : %d\n", account.accountNumber);
    printf("Account Holder : %s\n", account.name);
    printf("Balance        : %.2f\n", account.balance);
}

int main() {
    struct Account account;
    int choice;
    int accountCreated = 0;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                accountCreated = 1;
                break;

            case 2:
                if (accountCreated)
                    depositMoney(&account);
                else
                    printf("Please create an account first.\n");
                break;

            case 3:
                if (accountCreated)
                    withdrawMoney(&account);
                else
                    printf("Please create an account first.\n");
                break;

            case 4:
                if (accountCreated)
                    displayAccount(account);
                else
                    printf("Please create an account first.\n");
                break;

            case 5:
                printf("\nThank you for using the Bank Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
```
