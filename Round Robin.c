#include <stdio.h>

int main() {
    int n, i, timeQuantum, remaining;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burstTime[n], remainingTime[n];
    
    // Input Burst Time
    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i]; // Copy burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    int currentTime = 0, done;
    remaining = n;

    // Round Robin Execution
    while (remaining > 0) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0;
                if (remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                } else {
                    currentTime += remainingTime[i];
                    printf("Process %d finished at time %d\n", i + 1, currentTime);
                    remainingTime[i] = 0;
                    remaining--;
                }
            }
        }
        if (done) break;
    }

    return 0;
}

/*
Enter number of processes: 3
Enter Burst Time for each process:
Process 1: 5
Process 2: 8
Process 3: 3
Enter Time Quantum: 3

Process 3 finished at time 3
Process 1 finished at time 8
Process 2 finished at time 14
*/
