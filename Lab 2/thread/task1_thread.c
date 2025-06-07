#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunction(void *arg);
void createAndJoinThreads();

int main() {
    createAndJoinThreads();
    return 0;
}

void *threadFunction(void *arg) {
    int threadNumber = *((int *) arg);
    printf("Thread %d running\n", threadNumber);
    
    
    
    printf("Thread %d closed\n", threadNumber);
    pthread_exit(NULL);
}

void createAndJoinThreads() {
    pthread_t threads[5]; // Creating thread, array size 5
    int threadArgs[5];
    
    for (int i = 0; i < 5; i++) {
        threadArgs[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &threadArgs[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
}
