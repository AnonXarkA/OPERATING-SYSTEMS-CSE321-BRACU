#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_MSG_SIZE 6

struct msg {
    long int type;
    char txt[6];
};

void otpGenerator(int msgid);
void mailProcess(int msgid, struct msg send_msg);
void logIn(int msgid);

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    char workspace[MAX_MSG_SIZE];
    printf("Please enter the workspace name: ");
    scanf("%s", workspace);

    if (strcmp(workspace, "cse321") != 0) {
        printf("Invalid workspace name\n");
        msgctl(msgid, IPC_RMID, NULL);
        exit(0);
    }

    struct msg send_msg;
    send_msg.type = 1;
    strcpy(send_msg.txt, workspace);
    msgsnd(msgid, &send_msg, sizeof(send_msg) - sizeof(long int), 0);
    printf("Workspace name sent to otp generator from log in: %s\n", send_msg.txt);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        otpGenerator(msgid);
    } else {
        logIn(msgid);
        wait(NULL);
    }

    return 0;
}

void otpGenerator(int msgid) {
    struct msg recv_msg;
    msgrcv(msgid, &recv_msg, sizeof(recv_msg) - sizeof(long int), 1, 0);
    printf("OTP generator received workspace name from log in: %s\n", recv_msg.txt);

    pid_t otp_pid = getpid();
    struct msg send_msg;
    send_msg.type = 2;
    sprintf(send_msg.txt, "%d", otp_pid);
    msgsnd(msgid, &send_msg, sizeof(send_msg) - sizeof(long int), 0);
    printf("OTP sent to log in from OTP generator: %s\n", send_msg.txt);

    mailProcess(msgid, send_msg);
    exit(0);
}

void mailProcess(int msgid, struct msg send_msg) {
    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        send_msg.type = 3;
        msgsnd(msgid, &send_msg, sizeof(send_msg) - sizeof(long int), 0);
        printf("OTP sent to mail from OTP generator: %s\n", send_msg.txt);
        printf("Mail received OTP from OTP generator: %s\n", send_msg.txt);
        printf("OTP sent to log in from mail: %s\n", send_msg.txt);
        exit(0);
    } else {
        wait(NULL);
    }
}


void logIn(int msgid) {
    struct msg recv_msg;
    msgrcv(msgid, &recv_msg, sizeof(recv_msg) - sizeof(long int), 2, 0);
    printf("Log in received OTP from OTP generator: %s\n", recv_msg.txt);
    char otp_from_generator[MAX_MSG_SIZE];
    strcpy(otp_from_generator, recv_msg.txt);

    msgrcv(msgid, &recv_msg, sizeof(recv_msg) - sizeof(long int), 3, 0);
    printf("Log in received OTP from mail: %s\n", recv_msg.txt);

    int result = 1;
    for (int i = 0; i < MAX_MSG_SIZE; i++) {
        result &= (recv_msg.txt[i] == otp_from_generator[i]);
    }

    if (result) {
        printf("OTP Verified\n");
    } else {
        printf("OTP Incorrect\n");
    }

    msgctl(msgid, IPC_RMID, NULL);
}


