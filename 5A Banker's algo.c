#include <stdio.h>

int main() {
    int n, m, i, j, finished[5] = {0}, safeSeq[5], count = 0;
    int alloc[5][5], max[5][5], avail[5], need[5][5];

    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Need Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finished[i]) {
                int canAllocate = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) {
                        canAllocate = 0;
                        break;
                    }
                if (canAllocate) {
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];  // Release resources
                    safeSeq[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("Deadlock detected!\n");
            return 1;
        }
    }

    printf("Safe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}

/*
Enter number of processes and resources: 3 3

Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2

Enter Maximum Need Matrix:
7 5 3
3 2 2
9 0 2

Enter Available Resources: 3 3 2
Safe Sequence: P1 P0 P2
*/


