#include <bits/stdc++.h>
using namespace std;

#define rep(from,to) for (int i = from; i < to; i++)
#define ss second.second
#define sf second.first

int32_t main()
{

    int processNumber;
    // cout << "Enter the number of process: ";
    cin >> processNumber;

    // cout << "Enter the CPU times ";

    vector<pair<int, pair<int, int>>> process(processNumber);

    rep(0,processNumber)
    {
        int cpuTime;
        cin >> cpuTime;

        process[i].sf = cpuTime;
        process[i].ss = i;
    }

    // cout << "Enter the arrival times ";

    rep(0,processNumber)
    {
        int arrivalTime;
        cin >> arrivalTime;

        process[i].first = arrivalTime;
    }

    sort(process.begin(), process.end());

    vector<pair<int, pair<int, int>>> waitTurnTime(processNumber);

    waitTurnTime[0].first = process[0].ss;
    waitTurnTime[0].sf = 0;
    waitTurnTime[0].ss = process[0].sf;

    int cpuProcessTime = process[0].sf;

    rep(1,processNumber)
    {
        int currProcess = process[i].ss;
        // cout << "CURR PROCESS\t" << currProcess << endl;
        waitTurnTime[i].first = currProcess;

        int prevProcess = process[i - 1].ss;
        // cout << "PREV PROCESS\t" << prevProcess << endl;

        int currArrivalTime = process[i].first;
        // cout << "CURR ARRIVAL\t" << currArrivalTime << endl;

        int currWaitingTime = cpuProcessTime - currArrivalTime;
        // cout << "CURR WAITING TIME\t" << currWaitingTime << endl;
        waitTurnTime[i].sf = currWaitingTime;

        int currTurnaroundTime = currWaitingTime + process[i].sf;
        // cout << "CURR TURNAROUND TIME\t" << currTurnaroundTime << endl;
        waitTurnTime[i].ss = currTurnaroundTime;

        int currCpuTime = process[i].sf;
        // cout << "CURR CPU TIME\t" << currCpuTime << endl;

        cpuProcessTime += currCpuTime;

        // cout << endl;
    }

    rep(0,processNumber)
    {
        swap(process[i].first, process[i].ss);
    }

    sort(process.begin(), process.end());
    sort(waitTurnTime.begin(), waitTurnTime.end());

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    rep(0,processNumber)
    {
        cout << "Process " << process[i].first + 1 << ": Waiting Time: " << waitTurnTime[i].sf << " Turnaround Time: " << waitTurnTime[i].ss << endl;
        totalWaitingTime += waitTurnTime[i].sf;
        totalTurnaroundTime += waitTurnTime[i].ss;
    }

    cout << setprecision(2) << fixed ;

    cout << "Average Waiting time: " << (float)totalWaitingTime / (float)processNumber << endl;
    cout << "Average Turnaround time: " << (float)totalTurnaroundTime / (float)processNumber << endl;

    return 0;
}