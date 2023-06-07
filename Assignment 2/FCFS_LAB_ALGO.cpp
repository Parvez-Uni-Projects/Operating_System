#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    int processNumber;
    // cout << "Enter the number of process: ";
    cin >> processNumber;

    // cout << "Enter the CPU times ";

    vector<pair<int, pair<int, int>>> process(processNumber);

    for (int i = 0; i < processNumber; i++)
    {
        int cpuTime;
        cin >> cpuTime;

        process[i].second.first = cpuTime;
        process[i].second.second = i;
    }

    // cout << "Enter the arrival times ";

    for (int i = 0; i < processNumber; i++)
    {
        int arrivalTime;
        cin >> arrivalTime;

        process[i].first = arrivalTime;
    }

    sort(process.begin(), process.end());

    cout << " ARRIVAL TIME \t CPU TIME \t PROCESS NUMBER" << endl;

    for (int i = 0; i < processNumber; i++)
    {
        cout << process[i].first << "\t" << process[i].second.first << "\t" << process[i].second.second << endl;
    }

    cout << endl;

    vector<pair<int, int>> waitingTime(processNumber);

    waitingTime[0].first = 0;
    waitingTime[0].second = process[0].second.second;

    int cpuProcessTime = process[0].second.first;

    for (int i = 1; i < processNumber; i++)
    {
        int currProcess = process[i].second.second;
        int prevProcess = process[i - 1].second.second;

        // cout << "CURR \t" << currProcess << " PREV \t" << prevProcess << endl;
        // waitingTime[currProcess].second = currProcess;

        // cout << "CURR PROCESS\t" << waitingTime[currProcess].second << endl;

        // int currArrivalTime = process[i].first;
        // cout << "CURR ARRIVAL\t" << currArrivalTime << endl;

        // int prevCpuTime = process[i - 1].second.first;
        // cout << "PREV CPU TIME\t" << prevCpuTime << endl;

        // int prevWaitingTime = waitingTime[i-1].first;
        // cout << "PREV WAITING TIME\t" << prevWaitingTime << endl;

        // int currWaitingTime = prevCpuTime + prevWaitingTime - currArrivalTime;

        // cout << "CURR WAITING TIME\t" << currWaitingTime << endl;

        // waitingTime[i].first = currWaitingTime;

        int currArrivalTime = process[i].first;
        cout << "CURR ARRIVAL\t" << currArrivalTime << endl;

        int currWaitingTime = cpuProcessTime - currArrivalTime;
        cout << "CURR WAITING TIME\t" << currWaitingTime << endl;
        waitingTime[i].first = currWaitingTime;

        int currCpuTime = process[i].second.first;

        cpuProcessTime += currCpuTime;

        cout << endl;
    }

    cout << "WAITING TIME" << endl;

    for (int i = 0; i < processNumber; i++)
    {
        cout << waitingTime[i].first << " " << waitingTime[i].second << endl;
    }

    return 0;
}