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

    vector<pair<int, pair<int, int>>> waitTurnTime(processNumber);

    waitTurnTime[0].first = process[0].second.second;
    waitTurnTime[0].second.first = 0;
    waitTurnTime[0].second.second = process[0].second.first;

    int cpuProcessTime = process[0].second.first;

    for (int i = 1; i < processNumber; i++)
    {
        int currProcess = process[i].second.second;
        // cout << "CURR PROCESS\t" << currProcess << endl;
        waitTurnTime[i].first = currProcess;

        int prevProcess = process[i - 1].second.second;
        // cout << "PREV PROCESS\t" << prevProcess << endl;

        int currArrivalTime = process[i].first;
        // cout << "CURR ARRIVAL\t" << currArrivalTime << endl;

        int currWaitingTime = cpuProcessTime - currArrivalTime;
        // cout << "CURR WAITING TIME\t" << currWaitingTime << endl;
        waitTurnTime[i].second.first = currWaitingTime;

        int currTurnaroundTime = currWaitingTime + process[i].second.first;
        // cout << "CURR TURNAROUND TIME\t" << currTurnaroundTime << endl;
        waitTurnTime[i].second.second = currTurnaroundTime;

        int currCpuTime = process[i].second.first;
        // cout << "CURR CPU TIME\t" << currCpuTime << endl;

        cpuProcessTime += currCpuTime;

        // cout << endl;
    }

    for (int i = 0; i < processNumber; i++)
    {
        swap(process[i].first, process[i].second.second);
    }

    sort(process.begin(), process.end());
    sort(waitTurnTime.begin(), waitTurnTime.end());

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < processNumber; i++)
    {
        cout << "Process " << process[i].first + 1 << " : Waiting Time: " << waitTurnTime[i].second.first << " Turnaround Time: " << waitTurnTime[i].second.second << endl;
        totalWaitingTime += waitTurnTime[i].second.first;
        totalTurnaroundTime += waitTurnTime[i].second.second;
    }

    cout << "Average Waiting time:   " << (float)totalWaitingTime / (float)processNumber << endl;
    cout << "Average Turnaround time: " << (float)totalTurnaroundTime / (float)processNumber << endl;

    return 0;
}