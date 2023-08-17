#include <stdio.h>

#define MAX_HOLES 100
#define MAX_REQUESTS 100

int holes[MAX_HOLES];
int requests[MAX_REQUESTS];
int holesCount = 0;
int requestsCount = 0;

void worstFitAllocation() {
    int i, j;
    int allocated[MAX_REQUESTS] = {0};

    printf("Memory Allocation Step by Step:\n");
    for (i = 0; i < requestsCount; i++) {
        int maxHoleIndex = -1;
        int maxHoleSize = -1;

        for (j = 0; j < holesCount; j++) {
            if (holes[j] >= requests[i] && holes[j] > maxHoleSize) {
                maxHoleIndex = j;
                maxHoleSize = holes[j];
            }
        }

        if (maxHoleIndex != -1) {
            holes[maxHoleIndex] -= requests[i];
            allocated[i] = 1;
            printf("Request %d - %d allocated\n", i + 1, requests[i]);
        } else {
            printf("Request %d - %d not allocated\n", i + 1, requests[i]);
        }

        printf("Remaining Memory Size:\n");
        for (j = 0; j < holesCount; j++) {
            printf("Hole %d: %d\n", j + 1, holes[j]);
        }
        printf("------------------------\n");
    }
}

int calculateExternalFragmentation() {
    int externalFragmentation = 0;
    int i;

    for (i = 0; i < holesCount; i++) {
        externalFragmentation += holes[i];
    }

    return externalFragmentation;
}

int main() {
    holesCount = 5;
    holes[0] = 50;
    holes[1] = 200;
    holes[2] = 70;
    holes[3] = 115;
    holes[4] = 15;

    requestsCount = 10;
    requests[0] = 100;
    requests[1] = 10;
    requests[2] = 35;
    requests[3] = 15;
    requests[4] = 23;
    requests[5] = 6;
    requests[6] = 25;
    requests[7] = 55;
    requests[8] = 88;
    requests[9] = 40;

    worstFitAllocation();

    int externalFragmentation = calculateExternalFragmentation();
    printf("\nExternal Fragmentation: %d\n", externalFragmentation);

    return 0;
}
