
#include <stdio.h>
#define MAX_FRAMES 3  // Number of frames

int main() {
    int frames[MAX_FRAMES], refString[20], n, pageFaults = 0;
    int i, j, found, counter[MAX_FRAMES], time = 0, least;

    printf("Enter the reference string (end with 0): ");
    for (n = 0; n < 20; n++) {
        scanf("%d", &refString[n]);
        if (refString[n] == 0) break; // Stop input on 0
    }

    for (i = 0; i < MAX_FRAMES; i++) frames[i] = -1; // Initialize frames as empty

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == refString[i]) {  // Page hit
                found = 1;
                counter[j] = ++time; // Update usage time
                break;
            }
        }

        if (!found) { // Page fault
            least = 0;
            for (j = 1; j < MAX_FRAMES; j++)
                if (counter[j] < counter[least]) least = j; // Find LRU page

            frames[least] = refString[i]; // Replace LRU page
            counter[least] = ++time;
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
