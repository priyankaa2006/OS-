#include <stdio.h>

#define MAX_PAGES 100  // Maximum number of pages

int main() {
    int pageTable[MAX_PAGES];  // Page table to store frame numbers
    int pageNumber, offset, frameNumber;
    int pageSize, numPages, processSize, logicalAddress, physicalAddress;

    // Input process size and page size
    printf("Enter the process size (in KB): ");
    scanf("%d", &processSize);
    
    printf("Enter the page size (in KB): ");
    scanf("%d", &pageSize);

    // Calculate total number of pages
    numPages = processSize / pageSize;
    if (processSize % pageSize != 0)
        numPages++;

    printf("Total number of pages required: %d\n", numPages);

    // Input page table (Frame number for each page)
    printf("Enter the frame number for each page:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    // Input logical address
    printf("Enter the logical address (in KB): ");
    scanf("%d", &logicalAddress);

    // Calculate page number and offset
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    // Get frame number from page table
    if (pageNumber >= numPages) {
        printf("Error: Invalid page number. Address out of range!\n");
    } else {
        frameNumber = pageTable[pageNumber];
        physicalAddress = (frameNumber * pageSize) + offset;

        // Display result
        printf("\nLogical Address: %d KB\n", logicalAddress);
        printf("Page Number: %d\n", pageNumber);
        printf("Offset: %d KB\n", offset);
        printf("Frame Number: %d\n", frameNumber);
        printf("Physical Address: %d KB\n", physicalAddress);
    }

    return 0;
}
/*Input:
mathematica
Copy
Edit
Enter the process size (in KB): 500
Enter the page size (in KB): 100
Total number of pages required: 5
Enter the frame number for each page:
Page 0 -> Frame: 2
Page 1 -> Frame: 5
Page 2 -> Frame: 8
Page 3 -> Frame: 4
Page 4 -> Frame: 7
Enter the logical address (in KB): 320

Output:
yaml
Copy
Edit
Logical Address: 320 KB
Page Number: 3
Offset: 20 KB
Frame Number: 4
Physical Address: 420 KB*/
