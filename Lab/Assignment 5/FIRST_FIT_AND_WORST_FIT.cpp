
#include <iostream>
#include <vector>
using namespace std;

#define MAX_REQUESTS 100

vector<int> holes;
vector<int> requests;
int extFrag = 0;

void worstFitAllocation() {

    vector<int> allocated(requests.size(), 0);

    cout << "\n!!! Worst Fit Memory Allocation !!!\n";
    for (int i = 0; i < requests.size(); i++) {
        int maxHoleIndex = -1;
        int maxHoleSize = -1;

        for (int j = 0; j < holes.size(); j++) {
            if (holes[j] >= requests[i] && holes[j] > maxHoleSize) {
                maxHoleIndex = j;
                maxHoleSize = holes[j];
            }
        }

        if (maxHoleIndex != -1) {
            holes[maxHoleIndex] -= requests[i];
            allocated[i] = 1;
            cout << "Request " << i + 1 << " - " << requests[i] << " allocated\n";
        } else {
            cout << "Request " << i + 1 << " - " << requests[i] << " can not allocated \n !!! Terminating simulation !!! \n";

            return;
        }

        cout << "Remaining Memory Size:\n";
        for (int j = 0; j < holes.size(); j++) {
            cout << "Hole " << j + 1 << ": " << holes[j] << "\n";
        }
        cout << "------------------------\n";
    }
}


void firstFitAllocation() {
    int i, j;
    vector<int> allocated(requests.size(), 0);

    cout << "\n!!! First Fit Memory Allocation !!!\n";
    for (i = 0; i < requests.size(); i++) {
        bool allocatedFlag = false;

        for (j = 0; j < holes.size(); j++) {
            if (holes[j] >= requests[i]) {
                holes[j] -= requests[i];
                allocated[i] = 1;
                std::cout << "Request " << i + 1 << " - " << requests[i] << " allocated\n";
                allocatedFlag = true;
                break;
            }
        }

        if (!allocatedFlag) {
            std::cout << "Request " << i + 1 << " - " << requests[i] << " not allocated\n";
        }

        std::cout << "Remaining Memory Size:\n";
        for (j = 0; j < holes.size(); j++) {
            std::cout << "Hole " << j + 1 << ": " << holes[j] << "\n";
        }
        std::cout << "------------------------\n";
    }
}


void calculateextFrag() {

    for (int holeSize : holes) {
        extFrag += holeSize;
    }
}

int main() {
    

    requests = {100, 10, 35, 15, 23, 6, 25, 55, 88, 40};

    holes = {50, 200, 70, 115, 15};
    worstFitAllocation();

    holes = {50, 200, 70, 115, 15};
    firstFitAllocation();


    calculateextFrag();

    cout << "\nExternal Fragmentation: " << extFrag << "\n";

    return 0;
}
