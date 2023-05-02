#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char firstname[40], lastname[40];
int account_number, pin = 1234, amount = 1000;

// Main Functions
void depositMoney();
void withdrawMoney();
void accountDetails();
void transactionDetails();
// UTILS

int validatePin()
{

    int transactionPin;

    printf("Enter Transaction Pin: ");
    scanf("%d", &transactionPin);

    if (transactionPin == pin)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void endTransaction()
{
    char c;
    printf("\nPress enter to continue....\n");
    getchar();
}

void printTitle(char title[100])
{
    printf("\n================== %s ========================\n", title);
}

int main()
{
    int choice;
    printTitle("WELCOME TO DANNY BANK");

    printf("Enter first and last name: ");
    scanf("%s %s", firstname, lastname);

    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);

    printf("\nCreate PIN: ");
    scanf("%d", &pin);

    while (1)
    {
        printTitle("MAIN MENU");

        printf("1. Deposit Money \n");
        printf("2. Withdraw Money \n");
        printf("3. Account Details \n");
        printf("4. Transaction Details \n");
        printf("5. Exit \n");

        printf("WHAT DO YOU WANT TO DO? \n\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            depositMoney();
            break;
        case 2:
            withdrawMoney();
            break;

        case 3:
            accountDetails();
            break;
        case 4:
            transactionDetails();
        case 5:
            printTitle("Thank you for banking with us");
            exit(1);
            break;
        default:
            printf("Invalid Transaction");
        }
    }
}

void depositMoney()
{

    const int userPin = validatePin();

    if (userPin == 0)
    {
        printf("Invalid Pin");
    }
    else
    {
        int depositAmount;
        FILE *accountFile = fopen("Account.txt", "a");
        time_t currentTime;
        time(&currentTime);

        printf("\nHow much do you want to deposit? ");
        scanf("%d", &depositAmount);

        const int newAmount = amount + depositAmount;
        amount = newAmount;

        printf("\nYou have successfully deposited NGN%d into your account, your current account balance is  NGN%d\n\n", depositAmount, newAmount);

        fprintf(accountFile, "Transaction Type=>Credit\nDate & Time => %s\nAmount=> NGN%d\n\n", ctime(&currentTime), newAmount);

        fclose(accountFile);

        endTransaction();
    }
}

void withdrawMoney()
{
    const int userPin = validatePin();

    if (userPin == 0)
    {
        printf("Invalid pin");
    }
    else
    {
        int withdrawAmount;
        time_t currentTime;
        time(&currentTime);
        FILE *accountFile = fopen("Account.txt", "a");

        printf("\nHow much do you want to withdraw? ");
        scanf("%d", &withdrawAmount);

        if (amount < withdrawAmount)
        {
            printf("Insufficient balance");
        }
        else
        {
            const int newAmount = amount - withdrawAmount;
            amount = newAmount;

            printf("\nYou have successfully withdrawn NGN%d from your account, your current account balance is  NGN%d\n\n", withdrawAmount, newAmount);

            fprintf(accountFile, "Transaction Type=>Debit\nDate & Time => %s\nAmount=> NGN%d\n\n", ctime(&currentTime), newAmount);
        }
        fclose(accountFile);
    }
}

void transactionDetails()
{
    const int userPin = validatePin();

    if (userPin == 0)
    {
        printf("Invalid Pin");
    }
    else
    {
        FILE *accountFile = fopen("Account.txt", "r");

        char c = fgetc(accountFile);

        if (c == EOF)
        {
            printf("No Account History");
        }
        else
        {
            printTitle("TRANSACTION DETAILS");
            while (c != EOF)
            {
                c = fgetc(accountFile);

                printf("%c\n", c);
            }
        }

        fclose(accountFile);
    }
}

void accountDetails()
{
    const int userPin = validatePin();
    if (userPin == 0)
    {
        printf("Invalid pin");
    }
    else
    {
        printf("Name=> %s %s\nAccount Number=> %d", firstname, lastname, account_number);
    }
}