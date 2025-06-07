#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Check_palindrome(char *str) {
    
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        while (!isalnum(*start) && start < end) {
            start++;
        }
        while (!isalnum(*end) && start < end) {
            end--;
        }

        if (tolower(*start) != tolower(*end)) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }

    return 1; // Palindrome
}

void palindrome(char *str) {
    if (Check_palindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
}

int main() {
    char palindrome_str[1000];

    printf("Enter a string: ");
    scanf("%s", palindrome_str);

    palindrome(palindrome_str);

    return 0;
}