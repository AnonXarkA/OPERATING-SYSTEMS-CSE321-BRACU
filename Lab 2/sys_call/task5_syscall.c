
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// void printParentProcess() {
//     printf("1. Parent process ID: %d\n", getppid());
// }

void GrandchildProcesses() {
    pid_t g_pid;
    for (int i = 0; i < 3; i++) {
        g_pid = fork();
        if (g_pid == 0) {
            printf("%d. Grandchild process ID: %d\n", i + 3, getpid());
            exit(0); // Exit after printing ID to prevent further forking
        }
    }
}

int main() {
    pid_t c_pid;
    printf("1. Parent process ID: %d\n", getppid());

    c_pid = fork();
    if (c_pid == 0) {
        // Child process
        printf("2. Child process ID: %d\n", getpid());
        GrandchildProcesses();
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}
