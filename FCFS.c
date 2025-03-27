#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n], waitingTime[n], turnaroundTime[n];
    
    // Input process details
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    // Calculate Waiting Time and Turnaround Time
    int completionTime = 0;
    for (i = 0; i < n; i++) {
        if (completionTime < arrivalTime[i])
            completionTime = arrivalTime[i];  // Wait if CPU is idle
        waitingTime[i] = completionTime - arrivalTime[i];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        completionTime += burstTime[i];
    }

    // Display results
    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\n", i + 1, waitingTime[i], turnaroundTime[i]);

    return 0;
}

/*
Enter the number of processes: 3
Enter Arrival Time and Burst Time for each process:
Process 1: 0 5
Process 2: 1 3
Process 3: 2 8

Process	Waiting Time	Turnaround Time
1	0		5
2	4		7
3	6		14

*/
