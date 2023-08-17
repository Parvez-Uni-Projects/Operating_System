#include <bits/stdc++.h>
using namespace std;
void fifoPageReplacement(vector<int> referenceString, int numFrames) {
    deque<int> frames;
    int numPageReferences = referenceString.size();
    int pageFaults = 0;

    for (int i = 0; i < numPageReferences; i++) {
        int currentPage = referenceString[i];
        bool pageAbsent = find(frames.begin(), frames.end(), currentPage) == frames.end();

        if (pageAbsent) {
            if (frames.size() == numFrames) {
                frames.pop_front();
            }
            frames.push_back(currentPage);
            pageFaults++;
        }

        cout << "Time Step " << i + 1 << ": ";
        for (int frame : frames) {
            cout << frame << " ";
        }
        for (int j = frames.size(); j < numFrames; j++) {
            cout << "- ";
        }
        cout << "(" << (pageAbsent ? "Miss" : "Hit") << ")\n";
    }

    float pageFaultRate = static_cast<float>(pageFaults) / numPageReferences * 100;
    cout << "\nNumber of Page Faults (FIFO): " << pageFaults << "\n";
    cout << "Page Fault Rate (FIFO): " << fixed << setprecision(2) << pageFaultRate << "%\n";
}

void lruPageReplacement(vector<int> referenceString, int numFrames) {
    vector<int> frames(numFrames, -1);
    int numPageReferences = referenceString.size();
    int pageFaults = 0;
    vector<int> lastAccess(numFrames, -1);

    for (int i = 0; i < numPageReferences; i++) {
        int currentPage = referenceString[i];
        int isPagePresent = 0;
        int lruIndex;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == currentPage) {
                isPagePresent = 1;
                lastAccess[j] = i;
                break;
            }
        }

        if (!isPagePresent) {
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

        cout << "Time Step " << i + 1 << ": ";
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1) {
                cout << frames[j] << " ";
            } else {
                cout << "- ";
            }
        }
        cout << "(" << (isPagePresent ? "Hit" : "Miss") << ")\n";
    }

    float pageFaultRate = (float)(pageFaults) / numPageReferences * 100;
    cout << "\nNumber of Page Faults (LRU): " << pageFaults << "\n";
    cout << "Page Fault Rate (LRU): " << fixed << setprecision(2) << pageFaultRate << "%\n";
}

int main() {
    vector<int> referenceString = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int numFrames = 3;

    lruPageReplacement(referenceString, numFrames);
    fifoPageReplacement(referenceString, numFrames);

    return 0;
}
