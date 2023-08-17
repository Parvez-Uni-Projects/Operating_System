#include <iostream>
#include <vector>

#define MAX_REQUESTS 100

std::vector<int> holes;
std::vector<int> requests;

void worstFitAllocation() {
    int i, j;
    std::vector<int> allocated(requests.size(), 0);

    std::cout << "Memory Allocation Step by Step:\n";
    for (i = 0; i < requests.size(); i++) {
        int maxHoleIndex = -1;
        int maxHoleSize = -1;

        for (j = 0; j < holes.size(); j++) {
            if (holes[j] >= requests[i] && holes[j] > maxHoleSize) {
                maxHoleIndex = j;
                maxHoleSize = holes[j];
            }
        }

        if (maxHoleIndex != -1) {
            holes[maxHoleIndex] -= requests[i];
            allocated[i] = 1;
            std::cout << "Request " << i + 1 << " - " << requests[i] << " allocated\n";
        } else {
            std::cout << "Request " << i + 1 << " - " << requests[i] << " not allocated\n";
        }

        std::cout << "Remaining Memory Size:\n";
        for (j = 0; j < holes.size(); j++) {
            std::cout << "Hole " << j + 1 << ": " << holes[j] << "\n";
        }
        std::cout << "------------------------\n";
    }
}

int calculateExternalFragmentation() {
    int externalFragmentation = 0;

    for (int holeSize : holes) {
        externalFragmentation += holeSize;
    }

    return externalFragmentation;
}

int main() {
    holes = {50, 200, 70, 115, 15};

    requests = {100, 10, 35, 15, 23, 6, 25, 55, 88, 40};

    worstFitAllocation();

    int externalFragmentation = calculateExternalFragmentation();
    std::cout << "\nExternal Fragmentation: " << externalFragmentation << "\n";

    return 0;
}
