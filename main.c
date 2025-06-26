C Programming, File Handling, User Authentication, Command Line Interfaces, Data Persistence, Modular Design, Security Logic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct {
    int acc_no;
    char name[30];
    int pin;
    float balance;
} Account;

Account current_user;

// Load account from file
int load_account(int acc_no, int pin) {
    FILE *fp = fopen("accounts.txt", "r");
    if (!fp) return 0;

    while (fscanf(fp, "%d %s %d %f", &current_user.acc_no, current_user.name, &current_user.pin, &current_user.balance) != EOF) {
        if (current_user.acc_no == acc_no && current_user.pin == pin) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Save updated account to file
void save_account(Account updated) {
    FILE *fp = fopen("accounts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    Account acc;
    while (fscanf(fp, "%d %s %d %f", &acc.acc_no, acc.name, &acc.pin, &acc.balance) != EOF) {
        if (acc.acc_no == updated.acc_no) {
            fprintf(temp, "%d %s %d %.2f\n", updated.acc_no, updated.name, updated.pin, updated.balance);
        } else {
            fprintf(temp, "%d %s %d %.2f\n", acc.acc_no, acc.name, acc.pin, acc.balance);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

// ATM options menu
void atm_menu() {
    int choice;
    float amount;

    while (1) {
        printf("\n===== Welcome, %s =====\n", current_user.name);
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(" Your balance is ₹%.2f\n", current_user.balance);
                break;
            case 2:
                printf("Enter amount to deposit: ₹");
                scanf("%f", &amount);
                if (amount > 0) {
                    current_user.balance += amount;
                    save_account(current_user);
                    printf(" ₹%.2f deposited. New Balance: ₹%.2f\n", amount, current_user.balance);
                } else {
                    printf(" Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: ₹");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf(" Invalid amount.\n");
                } else if (amount > current_user.balance) {
                    printf(" Insufficient balance.\n");
                } else {
                    current_user.balance -= amount;
                    save_account(current_user);
                    printf(" ₹%.2f withdrawn. Remaining Balance: ₹%.2f\n", amount, current_user.balance);
                }
                break;
            case 4:
                printf(" You have been logged out.\n");
                return;
            default:
                printf(" Invalid option. Please try again.\n");
        }
    }
}

int main() {
    int acc_no, pin, attempts = 0;

    printf(" Welcome to Smart ATM Simulator\n");

    while (attempts < 3) {
        printf("Enter Account Number: ");
        scanf("%d", &acc_no);
        printf("Enter 4-digit PIN: ");
        scanf("%d", &pin);

        if (load_account(acc_no, pin)) {
            atm_menu();
            return 0;
        } else {
            printf(" Invalid credentials. Try again.\n");
            attempts++;
        }
    }

    printf(" Too many failed attempts. Exiting system.\n");
    return 1;
}

/*Create This File: accounts.txt (Example)
1010 John 1234 5000.00
1020 Riya 5678 8000.00*/
