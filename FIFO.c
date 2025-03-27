
#include <stdio.h>

#define MAX_FRAMES 3  // Number of frames

int main() {
    int frames[MAX_FRAMES], refString[20], n, pageFaults = 0;
    int i, j, k = 0, found;

    printf("Enter the reference string (end with 0): ");
    for (n = 0; n < 20; n++) {
        scanf("%d", &refString[n]);
        if (refString[n] == 0) break; // Stop input on 0
    }

    for (i = 0; i < MAX_FRAMES; i++) frames[i] = -1; // Initialize frames as empty

    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == refString[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {  // Page fault
            frames[k] = refString[i]; // Replace the oldest page
            k = (k + 1) % MAX_FRAMES;
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
