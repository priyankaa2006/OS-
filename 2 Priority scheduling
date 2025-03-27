#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], burstTime[n], priority[n], waitingTime[n], turnaroundTime[n];

    // Input Burst Time and Priority for each process
    printf("Enter Burst Time and Priority for each process:\n");
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &burstTime[i], &priority[i]);
    }

    // Sort processes by Priority (Lower number = Higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {  // Swap if priority is higher
                // Swap priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

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
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               process[i], priority[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    return 0;
}

/*
Enter the number of processes: 3
Enter Burst Time and Priority for each process:
Process 1: 5 2
Process 2: 3 1
Process 3: 8 3

Process	Priority	Burst Time	Waiting Time	Turnaround Time
2	1		3		0		3
1	2		5		3		8
3	3		8		8		16
*/
