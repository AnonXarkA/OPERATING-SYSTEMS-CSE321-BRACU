
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define NUM_NAMES 3
#define MAX_NAME_LENGTH 100

void *calculateSum(void *name);
void *threadFunction(void *name);

char names[NUM_NAMES][MAX_NAME_LENGTH];

int main() {
    pthread_t threads[NUM_NAMES];
    void *threadResults[NUM_NAMES];

    printf("Enter names:\n");
    for (int i = 0; i < NUM_NAMES; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    for (int i = 0; i < NUM_NAMES; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void *)names[i]);
    }

    for (int i = 0; i < NUM_NAMES; i++) {
        pthread_join(threads[i], &threadResults[i]);
    }

    int temp1 = *((int *)threadResults[0]);
    int temp2 = *((int *)threadResults[1]);
    int temp3 = *((int *)threadResults[2]);

    if ((temp2 == temp3) && (temp1 == temp2) && (temp1 == temp3)) {
        printf("Youreka\n");
    } else if ((temp2 == temp3) || (temp1 == temp2) || (temp1 == temp3)) {
        printf("Miracle\n");
    } else {
        printf("Hasta La Vista\n");
    }

    for (int i = 0; i < NUM_NAMES; i++) {
        free(threadResults[i]);
    }

    return 0;
}

void *threadFunction(void *name) {
    return calculateSum(name);
}

void *calculateSum(void *s) {
    char *name = (char *)s;
    int size = strlen(name);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += name[i];
    }
    int *result = (int *)malloc(sizeof(int));
    *result = sum;
    pthread_exit(result);
}
