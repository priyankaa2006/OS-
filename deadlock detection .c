#include <stdio.h>

#define PROCESSES 3  // Number of processes
#define RESOURCES 3  // Number of resources

// Function to check if deadlock exists
void detectDeadlock(int allocation[PROCESSES][RESOURCES], int request[PROCESSES][RESOURCES], int available[RESOURCES]) {
    int work[RESOURCES], finish[PROCESSES] = {0}; 
    int i, j, processExecuted, deadlockExists = 1;

    // Initialize work = available
    for (i = 0; i < RESOURCES; i++) {
        work[i] = available[i];
    }

    printf("Checking for deadlock...\n");

    while (1) {
        processExecuted = 0;

        for (i = 0; i < PROCESSES; i++) {
            if (!finish[i]) {  // Process is not finished
                int canExecute = 1;

                // Check if request <= work (can process execute?)
                for (j = 0; j < RESOURCES; j++) {
                    if (request[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute) {
                    // Process can execute, so add its allocated resources back to work
                    for (j = 0; j < RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1; // Mark process as finished
                    processExecuted = 1;
                }
            }
        }

        if (!processExecuted)  // No process could execute in this cycle
            break;
    }

    // Check if all processes are finished
    for (i = 0; i < PROCESSES; i++) {
        if (!finish[i]) {
            deadlockExists = 0;
            printf("Deadlock detected! Process %d is in deadlock.\n", i);
        }
    }

    if (deadlockExists)
        printf("No Deadlock detected!\n");
}

int main() {
    // Example Input (Change these values to test different scenarios)
    int allocation[PROCESSES][RESOURCES] = {
        {0, 1, 0}, 
        {2, 0, 0}, 
        {3, 0, 3}
    };

    int request[PROCESSES][RESOURCES] = {
        {0, 0, 0}, 
        {1, 0, 2}, 
        {0, 0, 0}
    };

    int available[RESOURCES] = {0, 0, 0};  // Resources available in the system

    detectDeadlock(allocation, request, available);

    return 0;
}
/*
Checking for deadlock...
Deadlock detected! Process 1 is in deadlock.
*/
