#include <stdio.h>
#include <stdlib.h>

void printUsage(char *programName) {
    printf("Usage: %s <numbers>\n", programName);
}

void printOddEven(int numbers[], int count) {
    printf("Odd/Even for each number:\n");
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2 == 0) {
            printf(" %d even ", numbers[i]);
        } else {
            printf(" %d odd ", numbers[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    int numbers[argc - 1];
    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    printOddEven(numbers, argc - 1);

    return 0;
}
