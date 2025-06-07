
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NUMBERS 100

void printUsage(char *programName) {
    printf("Usage: %s <numbers>\n", programName);
}

void sortNumbers(char *numbers[]) {
    execvp("./sort", numbers);
}

void printOddEven(char *numbers[]) {
    execvp("./oddeven", numbers);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        
        sortNumbers(argv);
    } else {
        
        wait(NULL);
        
        printOddEven(argv);
    }

    return 0;
}
