#include <bits/stdc++.h>
using namespace std;

#define rep(from, to) for (int i = from; i < to; i++)
#define ss second.second
#define sf second.first

#define vJumbo vector<pair<int, pair<int, int> > >
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

    // rep(0 , processNumber)
    // {
    //     cout << process[i].first << " " << process[i].sf << " " << process[i].ss << endl;
    // }

    priority_queue<pair<int, pair <int ,int>>> pq;

   

    pq.push({-1 * process[0].sf, {process[0].first, process[0].ss}});

    /*
    print the priority queue
    while (!pq.empty())
    {
        cout << pq.top().first * -1 << " " << pq.top().sf << " " << pq.top().ss << endl;
        pq.pop();
    }*/


    int cpuProcessTime = 0;

    int lastPushed = 0;

    vector<pair<int, pair<int, int> > > waitTurnTime(processNumber);

    while (!pq.empty())
    {
        int currCpuTime = pq.top().first * -1;
        int currArrivalTime = pq.top().sf;
        int currProcess = pq.top().ss;
        currCpuTime--;

        if (!processDone[currProcess])
        {
            waitTurnTime[currProcess].sf = cpuProcessTime - currArrivalTime;
            waitTurnTime[currProcess].first = currProcess;

        }

        processDone[currProcess] = true;

        

        //cout << "CURRENT CPU TIME " << cpuProcessTime << endl;

        if (lastPushed + 1 < processNumber)
        {
            if (process[lastPushed+1].first <= cpuProcessTime)
            {
                lastPushed++;
                //cout << "Process " << process[lastPushed].ss + 1 << " arrived at " << cpuProcessTime << endl;
                pq.push({-1 * process[lastPushed].sf, {process[lastPushed].first, process[lastPushed].ss}});
                
            }
        }

        //cout << "Process " << currProcess + 1 << " is running at " << cpuProcessTime << " second" << endl;
        pq.pop();

        if (currCpuTime > 0)
        {
            pq.push({currCpuTime * -1, {currArrivalTime, currProcess}});
        }
        else
        {
            //cout << "Process " << currProcess + 1 << " completed at " << cpuProcessTime << endl;
            waitTurnTime[currProcess].ss = waitTurnTime[currProcess].sf + cpuTime[currProcess];
            processDone[currProcess] = true;
        }

        cpuProcessTime++;

        //cout << endl;
        
    }
    

    

    

  

    // cout << "CURR P

    



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
