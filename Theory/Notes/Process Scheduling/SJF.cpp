#include <bits/stdc++.h>
using namespace std;

#define rep(from, to) for (int i = from; i < to; i++)
#define ss second.second
#define sf second.first

#define vJumbo vector<pair<int, pair<int, int>>>
vector<bool> processDone;

int getCurrentProcess(vJumbo process, int cpuProcessTime)
{

    int currProcess = -1;
    int minCpuTime = INT_MAX;

    rep(0, process.size())
    {
        int processNumber = process[i].ss;

        if (processDone[processNumber] == false)
        {
            int currArrivalTime = process[i].first;

            if (currArrivalTime <= cpuProcessTime)
            {
                int currCpuTime = process[i].sf;

                if (currCpuTime < minCpuTime)
                {
                    minCpuTime = currCpuTime;
                    currProcess = processNumber;
                }
            }
        }
    }

    return currProcess;
}

int32_t main()
{

    int processNumber;
    cout << "Enter the number of process: ";
    cin >> processNumber;

    cout << processNumber << endl;

    processDone.resize(processNumber, false);

    cout << "Enter the CPU times ";

    vJumbo process(processNumber);
    vector<int> cpuTime(processNumber);
    vector<int> arrivalTime(processNumber);
    rep(0, processNumber)
    {

        cin >> cpuTime[i];
        cout << cpuTime[i] << " ";

        process[i].sf = cpuTime[i];
        process[i].ss = i;
    }

     cout << "\nEnter the arrival times ";

    rep(0, processNumber)
    {

        cin >> arrivalTime[i];
        cout << arrivalTime[i] << " ";

        process[i].first = arrivalTime[i];
    }

    cout << endl;

    sort(process.begin(), process.end());

    vector<pair<int, pair<int, int>>> waitTurnTime(processNumber);

    waitTurnTime[0].first = process[0].ss;
    waitTurnTime[0].sf = 0;
    waitTurnTime[0].ss = process[0].sf;

    processDone[process[0].ss] = true;

    // cout << "CURR PROCESS\t" << process[0].ss << endl;

    int cpuProcessTime = process[0].sf;

    rep(1, processNumber)
    {

        int currProcess = getCurrentProcess(process, cpuProcessTime);
        processDone[currProcess] = true;

        // cout << "CURR PROCESS\t" << currProcess << endl;
        waitTurnTime[i].first = currProcess;

        int currArrivalTime = arrivalTime[currProcess];
        // cout << "CURR ARRIVAL\t" << currArrivalTime << endl;

        int currWaitingTime = cpuProcessTime - currArrivalTime;
        // cout << "CURR WAITING TIME\t" << currWaitingTime << endl;
        waitTurnTime[i].sf = currWaitingTime;

        int currCpuTime = cpuTime[currProcess];
        int currTurnaroundTime = currWaitingTime + currCpuTime;
        // cout << "CURR TURNAROUND TIME\t" << currTurnaroundTime << endl;
        waitTurnTime[i].ss = currTurnaroundTime;

        // cout << "CURR CPU TIME\t" << currCpuTime << endl;

        cpuProcessTime += currCpuTime;

        cout << endl;
    }

    rep(0, processNumber)
    {
        swap(process[i].first, process[i].ss);
    }

    sort(process.begin(), process.end());
    sort(waitTurnTime.begin(), waitTurnTime.end());

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    rep(0, processNumber)
    {
        cout << "Process " << process[i].first + 1 << ": Waiting Time: " << waitTurnTime[i].sf << " Turnaround Time: " << waitTurnTime[i].ss << endl;
        totalWaitingTime += waitTurnTime[i].sf;
        totalTurnaroundTime += waitTurnTime[i].ss;
    }

    cout << setprecision(2) << fixed;

    cout << "Average Waiting time : " << (float)totalWaitingTime / (float)processNumber << endl;
    cout << "Average Turnaround time : " << (float)totalTurnaroundTime / (float)processNumber << endl;

    return 0;
}

/*
3
5 7 9
4 0 2
*/