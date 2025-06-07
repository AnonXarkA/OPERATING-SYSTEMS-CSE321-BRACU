#include <stdio.h>
#include <string.h>


int Check_Upper(char c) {
    return (c >= 'A'  && c <= 'Z' );
}

int Check_Lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int CheckDigit(char c) {
    return (  c <= '9' && c >= '0')  ;
}

int CheckSpecial_C(char c) {
    return (c == '(' || c == '_' || c == '$'  ||  c == '#' ||  c == '@' ||  c == ')');
}

void check_Character(char password[], int *missingType, int (*checkFunc)(char)) {
    int pass_len = strlen(password);
    for (int x = 0; x < pass_len; x++) {
        if (checkFunc(password[x])) {
            *missingType = 0;
            break;
        }
    }
}

void Password_check(char password[]) {
    int upper_case = 1;
    int lower_case = 1;
    int digits = 1;
    int special_chr = 1;


    check_Character(password, &upper_case, Check_Upper);
    check_Character(password, &lower_case, Check_Lower);
    check_Character(password, &digits, CheckDigit);
    check_Character(password , &special_chr, CheckSpecial_C);

    if (lower_case) {
        printf("Lowercase character missing  ");
    }

    if (upper_case ){
        printf("Uppercase character missing  ");
    }

    if (digits) {
        printf("Digit missing");
    }

    if (special_chr) {
        printf("Special character missing  ");
    }

    if (!upper_case && !lower_case && !digits && !special_chr) {
        printf("OK\n");
    }




}

int main() {
    char password[1337];

    printf("Enter the password: ");
    scanf("%s", password);

    Password_check(password);

    return 0;
}