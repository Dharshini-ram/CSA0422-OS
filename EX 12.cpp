#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  // Number of philosophers

pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick up chopsticks
        if (id % 2 == 0) {  
            pthread_mutex_lock(&chopstick[id]);
            pthread_mutex_lock(&chopstick[(id + 1) % N]);
        } else {  
            pthread_mutex_lock(&chopstick[(id + 1) % N]);
            pthread_mutex_lock(&chopstick[id]);
        }

        printf("Philosopher %d is eating...\n", id);
        sleep(2);

        // Put down chopsticks
        pthread_mutex_unlock(&chopstick[id]);
        pthread_mutex_unlock(&chopstick[(id + 1) % N]);

        printf("Philosopher %d finished eating.\n", id);
    }
}

int main() {
    int i;
    pthread_t tid[N];
    int ids[N];

    // Initialize mutexes
    for (i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    // Create philosopher threads
    for (i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &ids[i]);
    }

    // Join threads
    for (i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

