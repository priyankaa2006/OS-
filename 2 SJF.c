#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], burstTime[n], waitingTime[n], turnaroundTime[n];

    // Input Burst Time
    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Sort processes by Burst Time (SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                // Swap burst time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                // Swap process number
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Calculate Waiting Time and Turnaround Time
    waitingTime[0] = 0; // First process has no waiting time
    for (i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    for (i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", process[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    return 0;
}

/*

Enter the number of processes: 3
Enter Burst Time for each process:
Process 1: 6
Process 2: 2
Process 3: 8

Process	Burst Time	Waiting Time	Turnaround Time
2	2		0		2
1	6		2		8
3	8		8		16

*/
