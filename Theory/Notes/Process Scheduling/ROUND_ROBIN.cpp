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

    cout << "SCHEDULE NUMBER : " << scheduleNumber << " QUANTAM TIME :  " << quantumNumber << endl;

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

        cout << startTime << "--" << process.second.second << "--" ;

        //cout << process.second.second << " ";

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

/*

Sample input 

10 4
A 0 11
b 3 7
c 9 12
d 11 13
e 17 6
f 19 17
g 24 3
h 30 7
i 32 6
j 42 3

Sample output

SCHEDULE NUMBER : 10 QUANTAM TIME :  4

0--A--4--b--8--A--12--b--15--c--19--d--23--A--26--e--30--f--34--c--38--d--42--g--45--h--49--e--51--i--55--f--59--c--63--j--66--d--70--h--73--i--75--f--79--d--80--f--84--f--
PROCESS	TAT 	WT 	RT
A  	26 	15 	0
b  	12 	5 	1
c  	54 	42 	6
d  	69 	56 	8
e  	34 	28 	9
f  	66 	49 	11
g  	21 	18 	18
h  	43 	36 	15
i  	43 	37 	19
j  	24 	21 	21
AVERAGE	39.2 	30.7	10.8

*/
