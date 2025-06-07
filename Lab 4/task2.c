#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h> 
/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; // indicating room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; // initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *far)
{
    int id = *(int *)far;
    while (1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        int index = in % warehouseSize;
        warehouse[index] = crops[id - 1];
        printf("Farmer %d: Insert crops %c at %d\n", id, warehouse[index], index);
        in++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void *ShopOwner(void *sho)
{
    int id = *(int *)sho;
    while (1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int index = out % warehouseSize;
        printf("Shop owner %d: Remove crops %c from %d\n", id, warehouse[index], index);
        warehouse[index] = 'N';
        out++;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1);
    }
}

int main()
{
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);

    int a[5] = {1, 2, 3, 4, 5}; 

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&Far[i], NULL, Farmer, &a[i]);
        pthread_create(&Sho[i], NULL, ShopOwner, &a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(Far[i], NULL);
        pthread_join(Sho[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}