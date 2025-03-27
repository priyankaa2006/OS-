#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;  // Semaphore declaration

void* process(void* arg) {
    int id = *((int*)arg);
    
    printf("Process %d is waiting...\n", id);
    sem_wait(&sem);  // Lock: Entering critical section

    // Critical Section (Only one process can execute this at a time)
    printf("Process %d is inside the critical section\n", id);
    sleep(2);  // Simulating some work in the critical section
    printf("Process %d is leaving the critical section\n", id);

    sem_post(&sem);  // Unlock: Leaving critical section
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    // Initialize the semaphore with value 1 (Binary Semaphore)
    sem_init(&sem, 0, 1);

    // Creating two threads (simulating two processes)
    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t2, NULL, process, &id2);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy the semaphore
    sem_destroy(&sem);

    printf("Both processes finished execution.\n");
    return 0;
}
/*Process 1 is waiting...
Process 2 is waiting...
Process 1 is inside the critical section
Process 1 is leaving the critical section
Process 2 is inside the critical section
Process 2 is leaving the critical section
Both processes finished execution.
*/
