#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_INTEGERS 5

void *thread_function(void *arg);

int main() {
    pthread_t thread_id[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        int *id = (int *)malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&thread_id[i], NULL, thread_function, (void *)id);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    free(arg); 

    int start_num = (thread_id - 1) * NUM_INTEGERS + 1;

    for (int i = 0; i < NUM_INTEGERS; i++) {
        printf("Thread %d prints %d\n", thread_id, start_num + i);
    }

    pthread_exit(NULL);
}

