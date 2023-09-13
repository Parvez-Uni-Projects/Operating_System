#include <bits/stdc++.h>

using namespace std;
int cylinder = 0;
bool cylinderGoingUp = true;

void printCost(int src, int des)
{
    // USE THIS PART TO SEE CALCULATIONS
    // cout << src << " - " << des << " = " << abs(src - des) << endl;
}

void FCFS(vector<int> req, int head)
{

    cout << "\n!!!!! FCFS START !!!!!" << endl;

    int n = req.size();
    int movement = 0;
    while (!req.empty()) {
        movement += abs(head - req.front());
        printCost(head, req.front());

        head = req.front();
        req.erase(req.begin());
    }

    cout << "FCFS movement : " << movement << endl;
}

void SSTF(vector<int> req, int head)
{

    cout << "\n!!!!! SSTF START !!!!!" << endl;
    int n = req.size();

    int movement = 0;

    while (!req.empty()) {
        int min = 1000, index = 0;

        for (int i = 0; i < req.size(); i++) {
            if (abs(head - req[i]) < min) {
                min = abs(head - req[i]);
                index = i;
            }
        }

        movement += min;
        printCost(head, req[index]);
        head = req[index];
        req.erase(req.begin() + index);
    }

    cout << "SSTF movement : " << movement << endl;
}

int goUpTillX(int head, int nextMove, vector<int> req, int x)
{
    int movement = 0;

    int n = req.size();

    while (nextMove < x) {

        movement += abs(head - req[nextMove]);
        printCost(head, req[nextMove]);
        head = req[nextMove];
        nextMove++;
    }

    return movement;
}

int goDownTillX(int head, int nextMove, vector<int> req, int x)
{
    int movement = 0;
    --nextMove;
    while (nextMove >= x) {
        movement += abs(head - req[nextMove]);
        printCost(head, req[nextMove]);
        head = req[nextMove];
        nextMove--;
    }

    return movement;
}

void SCAN(vector<int> req, int head)
{
    cout << "\n!!!!! SCAN START !!!!!" << endl;

    int n = req.size();
    int movement = 0;

    sort(req.begin(), req.end());

    int nextMove = upper_bound(req.begin(), req.end(), head) - req.begin();

    if (cylinderGoingUp) {

        movement += goUpTillX(head, nextMove, req, n);
        movement += cylinder - req[n - 1];
        printCost(cylinder, req[n - 1]);
        head = cylinder;

        movement += goDownTillX(head, nextMove, req, 0);
    } else {
        movement += goDownTillX(head, nextMove, req, 0);
        movement += req[0];
        printCost(req[0], 0);
        head = 0;
        movement += goUpTillX(head, nextMove, req, n);
    }

    cout << "SCAN movement : " << movement << endl;
}

void CSCAN(vector<int> req, int head)
{
    cout << "\n!!!!! C - SCAN START !!!!!" << endl;
    int n = req.size();
    int movement = 0;

    sort(req.begin(), req.end());

    int nextMove = upper_bound(req.begin(), req.end(), head) - req.begin();

    if (cylinderGoingUp) {

        movement += goUpTillX(head, nextMove, req, n);
        movement += cylinder - req[n - 1];
        printCost(cylinder, req[n - 1]);
        head = 0;

        movement += goUpTillX(head, 0, req, nextMove);
    } else {
        movement += goDownTillX(head, nextMove, req, 0);
        movement += req[0];
        printCost(req[0], 0);
        head = cylinder;
        movement += goDownTillX(head, n, req, nextMove);
    }

    cout << "CSCAN movement : " << movement << endl;
}

void LOOK(vector<int> req, int head)
{
    cout << "\n!!!!! LOOK START !!!!!" << endl;

    int n = req.size();
    int movement = 0;

    sort(req.begin(), req.end());

    int nextMove = upper_bound(req.begin(), req.end(), head) - req.begin();

    if (cylinderGoingUp) {

        movement += goUpTillX(head, nextMove, req, n);
        head = req[n - 1];
        movement += goDownTillX(head, nextMove, req, 0);
    } else {
        movement += goDownTillX(head, nextMove, req, 0);
        head = req[0];
        movement += goUpTillX(head, nextMove, req, n);
    }

    cout << "LOOK movement : " << movement << endl;
}

void CLOOK(vector<int> req, int head)
{
    cout << "\n!!!!! C - LOOK START !!!!!" << endl;
    int n = req.size();
    int movement = 0;

    sort(req.begin(), req.end());

    int nextMove = upper_bound(req.begin(), req.end(), head) - req.begin();

    if (cylinderGoingUp) {

        movement += goUpTillX(head, nextMove, req, n);

        head = req[0];

        movement += goUpTillX(head, 0, req, nextMove);
    } else {
        movement += goDownTillX(head, nextMove, req, 0);

        head = req[n - 1];
        movement += goDownTillX(head, n, req, nextMove);
    }

    cout << "CSCAN movement : " << movement << endl;
}

int main()
{
    int n, head;
    // cout << "Enter total cylinder number and the number of requests: ";
    cin >> cylinder >> n;
    cylinder--;

    // DEFINE CYLINDER DIRECTION
    cylinderGoingUp = true;

    vector<int> req;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > cylinder)
        {
            continue;
        }
        req.push_back(x);
    }

    // cout << "Enter the current head position: ";
    cin >> head;

    // print the requests

    // cout << "The requests are: ";

    // for (int i = 0; i < n; i++) {
    //     cout << req[i] << " ";
    // }

     SSTF(req, head);

    FCFS(req, head);
    SCAN(req, head);
    CSCAN(req, head);
    LOOK(req, head);
    CLOOK(req, head);

    return 0;
}

/*

Sample input 1 : 

400 19
122 26 113 13 22 109 180 70 37 162 142 29 10 310 79 210 121 32 13
101

Sample output 1 : 
!!!!! SSTF START !!!!!
SSTF movement : 509

!!!!! FCFS START !!!!!
FCFS movement : 1750

!!!!! SCAN START !!!!!
SCAN movement : 687

!!!!! C - SCAN START !!!!!
CSCAN movement : 377

!!!!! LOOK START !!!!!
LOOK movement : 509

!!!!! C - LOOK START !!!!!
CSCAN movement : 278



Sample input 2 : 
200 8
98 183 37 122 14 124 65 67
53

Sample output 2 : 

!!!!! SSTF START !!!!!
SSTF movement : 236

!!!!! FCFS START !!!!!
FCFS movement : 640

!!!!! SCAN START !!!!!
SCAN movement : 331

!!!!! C - SCAN START !!!!!
CSCAN movement : 183

!!!!! LOOK START !!!!!
LOOK movement : 299

!!!!! C - LOOK START !!!!!
CSCAN movement : 153


*/
