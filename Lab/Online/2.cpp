#include <bits/stdc++.h>

using namespace std;

int main ()
{

    int scheduleNumber = 0 , quantamNumber = 0;

    cout << " ENTER SCHEDULE NUMBER : " << endl;

    cin >> scheduleNumber;

    cout << " ENTER QUANTAM NUMBER : " << endl;
    cin >> quantamNumber;

    vector<int> mapCompletionTime(scheduleNumber) , processArrivalTime(scheduleNumber) , mapBrustTime (scheduleNumber), mapCpuFirstTime(scheduleNumber);


    cout << scheduleNumber << " " << quantamNumber << endl;

    vector < pair <int , pair<int , int>>> schedule(scheduleNumber);

    cout << "ENTER THE CPU TIMES " << endl;

    for (int i = 0 ;i < scheduleNumber; i++)
    {

        cin >> schedule[i].second.first;
        schedule[i].second.second = i;
    }

    cout << "ENTER THE ARRIVAL TIMES " << endl;

    for (int i = 0 ;i < scheduleNumber; i++)
    {

        cin >> schedule[i].first;
    }
/*
    for (int i = 0 ;i< scheduleNumber ;  i++)
    {

        cout << schedule[i].second.second  << " " << schedule[i].first << " " << schedule[i].second.first << endl;
     }

     */

    cout << " AFTER SORTING " << endl;
     sort(schedule.begin() , schedule.end());


     for (int i = 0 ;i< scheduleNumber ;  i++)
    {

        cout << schedule[i].second.second  << " " << schedule[i].first << " " << schedule[i].second.first << endl;
     }

     queue< pair < int , pair <int , int>>> q;

     int lastPushed = 0;
     q.push(schedule[lastPushed]);

     int startTime = 0;
     int elapsedTime = 0;

     map <int , int > mp;

     mapCpuFirstTime[schedule[lastPushed].second.second] = startTime;

     mp[schedule[lastPushed].second.second]  = 2;

     int processed = 1;


    cout << " GANTT CHART  " << endl;

    cout << startTime ;

     while( !q.empty()  || processed < scheduleNumber)
     {

        if (q.empty()  && processed < scheduleNumber)
        {

         lastPushed++;
         q.push(schedule[lastPushed]);

         startTime = schedule[lastPushed].first;

         elapsedTime = startTime;
         processed++;

         mapCpuFirstTime[schedule[lastPushed].second.second] = startTime;
         mp[schedule[lastPushed].second.second]  = 2;

        }

        auto process = q.front();

        q.pop();

        if (mp[process.second.second] == 1)
        {
            mapCpuFirstTime[process.second.second] = startTime;
            mp[process.second.second] =2;
        }

        if (process.second.first > quantamNumber)
        {
            elapsedTime += quantamNumber;
            process.second.first-= quantamNumber;
        }
        else
        {
            elapsedTime += process.second.first;
            process.second.first = 0;
        }

        for (int i = lastPushed ; i <scheduleNumber ; i++)
        {
            if (mp[schedule[i].second.second] == 0 && schedule[i].first <= elapsedTime)
            {
                mp[schedule[i].second.second] = 1;
                q.push(schedule[i]);
                processed++;
                lastPushed =i;
            }
        }

        if (process.second.first != 0)
        {
            q.push(process);

        }
        else
        {
            mapCompletionTime[process.second.second] = elapsedTime;
        }

        cout << " --P" << process.second.second + 1 <<  "-- " << elapsedTime << " ";

        startTime = elapsedTime;

     }





}

/*

4 3
5 7 9 9
4 0 6 10

*/