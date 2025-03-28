#include <stdio.h>

#define MAX 10  // Maximum number of memory blocks and processes

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;  // Initialize all allocations to -1 (unallocated)
    }

    // Assign memory blocks using First Fit
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {  
            if (blockSize[j] >= processSize[i]) {  
                allocation[i] = j;
                blockSize[j] -= processSize[i];  
                break;  
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n;
    int blockSize[MAX], processSize[MAX];

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of %d memory blocks: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize, m, processSize, n);

    return 0;
}
/* 
Sample Input:
yaml
Copy
Enter the number of memory blocks: 4
Enter the sizes of 4 memory blocks: 10 20 30 40
Enter the number of processes: 5
Enter the sizes of 5 processes: 12 18 15 25 30
Sample Output:
mathematica
Copy
First Fit Allocation:
Process No.    Process Size    Block No.
1              12              1
2              18              2
3              15              3
4              25              4
5              30              Not Allocated
*/
