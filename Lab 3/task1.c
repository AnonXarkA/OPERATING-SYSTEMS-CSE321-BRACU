#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


struct shared {
char sel[100];
int b;
};


void addMoney(int *balance) {
int amount;
printf("Enter the amount to be added: ");
scanf("%d", &amount);


if (amount > 0) {
    *balance += amount;
    printf("Balance added successfully\n");
    printf("Updated balance after addition: %d\n", *balance);
} else {
    printf("Adding failed, Invalid amount\n");
}

}


void withdraw(int *balance) {
int amount;
printf("Enter the amount to be withdrawn: ");
scanf("%d", &amount);


if (amount > 0 && amount <= *balance) {
    *balance -= amount;
    printf("Balance withdrawn successfully\n");
    printf("Updated balance after withdrawal: %d\n", *balance);
} else {
    printf("Withdrawal failed, Invalid amount\n");
}

}


void check_money(int *balance) {
printf("Your current balance is: %d\n", *balance);
}


int main() {
int shmid;
key_t key;
struct shared *shm;


key = ftok("shmfile", 65);
shmid = shmget(key, sizeof(struct shared), IPC_CREAT | 0666);
shm = (struct shared *)shmat(shmid, NULL, 0);
shm->b = 1000;

char selection;
printf("Provide Your Input from Given Options:\n");
printf("1. Type a to Add Money\n");
printf("2. Type w to Withdraw Money\n");
printf("3. Type c to Check Balance\n");
scanf(" %c", &selection);

strcpy(shm->sel, &selection);
printf("Your selection: %c\n", selection);

int pid = fork();

if (pid == 0) {
    
    if (selection == 'a') {
        addMoney(&(shm->b));
    } else if (selection == 'w') {
        withdraw(&(shm->b));
    } else if (selection == 'c') {
        check_money(&(shm->b));
    } else {
        printf("Invalid selection\n");
    }

    exit(0);
} else {
    
    wait(NULL);
    char pipeMsg[100];
    int pipefd[2];
    pipe(pipefd);

    if (pid > 0) {
        
        close(pipefd[1]);
        read(pipefd[0], pipeMsg, sizeof(pipeMsg));
        printf("%s\n", pipeMsg);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }
}

return 0;

}



