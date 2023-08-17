#include <stdio.h>

int main() {
    int numPages = 8;
    int numPageReferences = 22;
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int numFrames = 3;
    int frames[numFrames];
    int pageFaults = 0;
    int lastAccess[numFrames];

    // Initialize the frames and lastAccess arrays
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
        lastAccess[i] = -1;
    }

    // Implement the LRU page replacement algorithm
    for (int i = 0; i < numPageReferences; i++) {
        int currentPage = referenceString[i];
        int isPagePresent = 0;
        int lruIndex;

        // Check if the page is already present in the frame
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                isPagePresent = 1;
                lastAccess[j] = i;
                break;
            }
        }

        if (!isPagePresent) {
            // Page fault: Find the index of the least recently used page
            lruIndex = 0;
            for (int j = 1; j < numFrames; j++) {
                if (lastAccess[j] < lastAccess[lruIndex]) {
                    lruIndex = j;
                }
            }

            frames[lruIndex] = currentPage;
            lastAccess[lruIndex] = i;
            pageFaults++;
        }

        // Print the current state of the frames
        printf("Time Step %d: ", i + 1);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("(%s)\n", isPagePresent ? "Hit" : "Miss");
    }

    // Calculate and display the page fault rate
    float pageFaultRate = (float)pageFaults / numPageReferences * 100;
    printf("\nNumber of Page Faults (LRU): %d\n", pageFaults);
    printf("Page Fault Rate (LRU): %.2f%%\n", pageFaultRate);

    return 0;
}

