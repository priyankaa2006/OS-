#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function prototype for thread function
void *thread_function(void *arg);

int main() {
    pthread_t thread_id;  // Declare thread ID
    int result;

    printf("Main process started...\n");

    // Create a new thread
    result = pthread_create(&thread_id, NULL, thread_function, NULL);
    
    // Check for thread creation error
    if (result != 0) {
        printf("Error creating thread\n");
        return 1;
    }

    printf("Thread created successfully. Thread ID: %lu\n", thread_id);

    // Wait for the thread to complete execution
    pthread_join(thread_id, NULL);

    printf("Thread execution completed successfully.\n");
    
    printf("Main process finished.\n");

    return 0;
}

// Thread function definition
void *thread_function(void *arg) {
    printf("Thread is running...\n");
    pthread_exit(NULL);
}
/*
Main process started...
Thread created successfully. Thread ID: 123456
Thread is running...
Thread execution completed successfully.
Main process finished.
*/
