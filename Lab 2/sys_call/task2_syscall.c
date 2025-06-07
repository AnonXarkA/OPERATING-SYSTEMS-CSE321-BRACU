#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void child_grandchild_process() {
    pid_t grandchild_pid = fork();

    if (grandchild_pid == 0) {
        printf("I am grandchild.\n");
    } else {
        wait(NULL);
        printf("I am child.\n");
    }
}

void parent_process() {
    wait(NULL);
    printf("I am parent.\n");
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        
        child_grandchild_process();
    } else {
        
        parent_process();
    }

    return 0;
}
