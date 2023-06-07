#include <bits/stdc++.h>

using namespace std;
int main()
{

    int scheduleNumber = 0, quantumNumber = 0;
    cin >> scheduleNumber >> quantumNumber;
    map<char, int> mapCompletionTime;
    map<char, int> processArrivalTime;
    map<char, int> mapBrustTime;
    map<char, int> mapCpuFirstTime;

    cout << "ARRIVAL TIME : " << scheduleNumber << " QUANTAM TIME :  " << quantumNumber << endl;

    cout << endl;

    vector<pair<int, pair<int, char>>> schedule(scheduleNumber);

    for (int i = 0; i < scheduleNumber; i++)
    {
        char process;
        int arrivalTime, cpuBrustTime;
        cin >> process >> arrivalTime >> cpuBrustTime;

        processArrivalTime[process] = arrivalTime;
        mapBrustTime[process] = cpuBrustTime;

        schedule[i].first = arrivalTime;
        schedule[i].second.first = cpuBrustTime;
        schedule[i].second.second = process;
    }

    sort(schedule.begin(), schedule.end());

    // for (int i = 0; i < scheduleNumber; i++)
    // {
    //     cout << schedule[i].second.second << " \t" << schedule[i].first << " \t" << schedule[i].second.first << endl;
    // }

    queue<pair<int, pair<int, char>>> q;

    int last_pushed = 0;
    q.push(schedule[last_pushed]);

    int startTime = 0;
    int elapsedTime = 0;
    map<char, int> mp;
    int processed = 1;

    mapCpuFirstTime[schedule[last_pushed].second.second] = startTime;
    mp[schedule[last_pushed].second.second] = 2;

    int breaker = 0;

    while (!q.empty() || processed < scheduleNumber)
    {

        // cout << "Iteration : " << breaker << " ";

        if (q.empty() && processed < scheduleNumber)
        {
            last_pushed++;
            q.push(schedule[last_pushed]);

            startTime = schedule[last_pushed].first;

            elapsedTime = startTime;
            processed++;
            mapCpuFirstTime[schedule[last_pushed].second.second] = startTime;
            mp[schedule[last_pushed].second.second] = 2;
        }
        auto process = q.front();
        q.pop();

        if (mp[process.second.second] == 1)
        {

            mapCpuFirstTime[process.second.second] = startTime;
            mp[process.second.second] = 2;
            // cout << "HIT"<< " " << startTime  << " " << mp[process.second.second] << endl;
        }

        if (process.second.first > quantumNumber)
        {

            elapsedTime += quantumNumber;
            process.second.first -= quantumNumber;
        }
        else
        {
            elapsedTime += process.second.first;
            process.second.first = 0;
        }

        for (int i = last_pushed; i < scheduleNumber; i++)
        {
            if (mp[schedule[i].second.second] == 0 && schedule[i].first <= elapsedTime)
            {

                mp[schedule[i].second.second] = 1;
                q.push(schedule[i]);
                processed++;
                last_pushed = i;
            }
        }

        if (process.second.first != 0)
            q.push(process);
        else
        {
            mapCompletionTime[process.second.second] = elapsedTime;
        }

        // cout << startTime << " " << process.second.second << " " << elapsedTime << endl;

        cout << process.second.second << " ";

        startTime = elapsedTime;

        breaker++;

        // cout << endl;
    }
    // print the mapCompletionTime map with key and value
    cout << endl;

    cout << "PROCESS\tTAT \tWT \tRT" << endl;

    int sumTat = 0, sumWat = 0, sumRt = 0;

    for (auto process : mapCompletionTime)
    {
        int CompletionTime = process.second;
        int arrivalTime = processArrivalTime[process.first];
        int brustTime = mapBrustTime[process.first];
        int cpuFirstTime = mapCpuFirstTime[process.first];

        int tat = process.second - arrivalTime;
        int wat = tat - brustTime;
        int rt = cpuFirstTime - arrivalTime;

        sumTat += tat;
        sumWat += wat;
        sumRt += rt;
        cout << process.first << "  \t" << tat << " \t" << wat << " \t" << rt << endl;
    }

    cout << "AVERAGE\t" << sumTat / float(scheduleNumber) << " \t" << sumWat / float(scheduleNumber) << "\t" << sumRt / float(scheduleNumber) << endl;
}