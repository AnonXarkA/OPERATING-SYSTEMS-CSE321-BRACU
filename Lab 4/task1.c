#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10 
#define BUFLEN 6
#define NUMTHREAD 2

void * producer(void *arg);
void * consumer(void *arg);
char buffer[BUFLEN];
char source[BUFLEN];
int pCount = 0;
int cCount = 0;
int buflen;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;

int thread_id[NUMTHREAD];
int i = 0;
int j = 0;

int main()
{
    int i;
    pthread_t thread[NUMTHREAD];
    thread_id[0] = 0;
    thread_id[1] = 1;
    memmove(source, "abcdef", 6);
    buflen = 6;

    for (i = 0; i < NUMTHREAD; i++)
    {
        if (i == 0)
            pthread_create(&thread[i], NULL, producer, (void *)&thread_id[i]);
        else
            pthread_create(&thread[i], NULL, consumer, (void *)&thread_id[i]);
    }

    for (i = 0; i < NUMTHREAD; i++)
    {
        pthread_join(thread[i], NULL);
    }

    return 0;
}

void * producer(void *arg)
{
    int *id = (int *)arg;

    while (1)
    {
        pthread_mutex_lock(&count_mutex);

        while (pCount == MAX)
        {
            pthread_cond_wait(&full, &count_mutex);
        }

        if (i == buflen)
            i = 0;

        buffer[pCount] = source[i];
        printf("%d produced %c by Thread %d\n", pCount, buffer[pCount], *id);
        i++;
        pCount++;

        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);

        sleep(1);
    }
}

void * consumer(void *arg)
{
    int *id = (int *)arg;

    while (1)
    {
        pthread_mutex_lock(&count_mutex);

        while (cCount == MAX || pCount == 0)
        {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }

        printf("%d consumed %c by Thread %d\n", cCount, buffer[cCount], *id);
        cCount++;

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);

        sleep(1);
    }
}