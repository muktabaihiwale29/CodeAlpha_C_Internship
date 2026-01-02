#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    struct bank b;
    FILE *fp;

    fp = fopen("bank.dat", "ab");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &b.accNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &b.balance);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

void displayAccounts() {
    struct bank b;
    FILE *fp;

    fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    printf("\n--- Bank Accounts ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("Acc No: %d | Name: %s | Balance: %.2f\n",
               b.accNo, b.name, b.balance);
    }

    fclose(fp);
}

void depositMoney() {
    struct bank b;
    FILE *fp;
    int acc;
    float amount;

    fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.accNo == acc) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            b.balance += amount;
            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);

            printf("Deposit successful!\n");
            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}

void withdrawMoney() {
    struct bank b;
    FILE *fp;
    int acc;
    float amount;

    fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.accNo == acc) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (b.balance >= amount) {
                b.balance -= amount;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }

            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}

void balanceEnquiry() {
    struct bank b;
    FILE *fp;
    int acc;

    fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.accNo == acc) {
            printf("Account Holder: %s\n", b.name);
            printf("Current Balance: %.2f\n", b.balance);
            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Balance Enquiry\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                balanceEnquiry();
                break;
            case 6:
                printf("Thank you for using banking system.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
