/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menu();
void signup();
void login();
void forget();
void change_password();
void delete_account();
void takepassword(char* pass);

struct account {
    char first_name[20];
    char last_name[20];
    char username[30];
    char phone[15];
    char gender;
    char DOB[10];
    char password[50];
};

int main() {
    while (1) {
        switch (menu()) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                forget();
                break;
            case 4:
                change_password();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}

int menu() {
    int c;
    printf("MAIN MENU\n");
    printf("1. SIGNUP\n");
    printf("2. LOGIN\n");
    printf("3. FORGET PASSWORD OR USERNAME\n");
    printf("4. CHANGE PASSWORD\n");
    printf("5. DELETE ACCOUNT\n");
    printf("6. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &c);

    return c;
}

void takepassword(char* pass) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == 13) { // Enter key
            pass[i] = '\0';
            break;
        } else if (ch == 8) { // Backspace key
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else if (ch == 9 || ch == 32) { // Tab or Space key
            continue;
        } else {
            pass[i++] = ch;
            printf("*");
        }
    }
}

void signup() {
    struct account u;
    char pass2[20];
    
    printf("CREATING NEW ACCOUNT\n");
    printf("Enter your first name: ");
    scanf("%s", u.first_name);
    printf("Enter last name: ");
    scanf("%s", u.last_name);
    printf("Enter your username: ");
    scanf("%s", u.username);
    printf("Enter your phone number: ");
    scanf("%s", u.phone);
    printf("Enter Gender: ");
    scanf(" %c", &u.gender); // Note the space before %c to consume any leftover newline character
    printf("Enter your DOB (DD/MM/YYYY): ");
    scanf("%s", u.DOB);
     fflush(stdin);
    
    // We are not using scanf to show the password, so we are making another function
    printf("Enter password: ");
    takepassword(u.password);
    
    // Ask the user to confirm the password
    printf("\nConfirm password: ");
    takepassword(pass2);
    
    if (strcmp(u.password, pass2) != 0) 
    {
        printf("\nPasswords do not match. Please try again.\n");
    } 
    else
    {
        printf("\nACCOUNT CREATED SUCCESSFULLY\n");
        // Save account to a file or database
        getch();
        
        FILE *fp = fopen("account.txt","w");
        fwrite (&u,sizeof(struct account),1,fp);
        fclose(fp);
        }
    
}

void login() {
    // Implementation for login
}

void forget() {
    // Implementation for forget password or username
}
       
void change_password() {
    // Implementation for change password
}

void delete_account() {
    // Implementation for delete account
}

