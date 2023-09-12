#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int resourceNumber, processNumber;

void printMatrix(vector<int> v[])
{
    for (int i = 0; i < processNumber; i++) {
        cout << "p" << i + 1 << " ";

        for (int j = 0; j < resourceNumber; j++) {
            cout << " " << v[i][j];
        }
        cout << endl;
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << " Number of resoruces" << endl;
    cin >> resourceNumber;

    // cout << "Number of process " << endl;
    cin >> processNumber;

    vector<int> allocation[processNumber], mx[processNumber], need[processNumber];

    vector<int> instances(resourceNumber);

    for (int i = 0; i < resourceNumber; i++) {

        // cout << "Total number of resource for " << (char)('A' + i) << endl;
        cin >> instances[i];
    }

    cout << "Enter the allocation matrix : " << endl;

    for (int i = 0; i < processNumber; i++) {
        // cout << "Allocations for process p" << i + 1 << endl;

        for (int j = 0; j < resourceNumber; j++) {
            int x;
            cin >> x;
            allocation[i].push_back(x);
        }
    }

    printMatrix(allocation);
    cout << "Enter the max matrix : " << endl;

    for (int i = 0; i < processNumber; i++) {
        // cout << "Max for process p" << i + 1 << endl;

        for (int j = 0; j < resourceNumber; j++) {
            int x;
            cin >> x;
            mx[i].push_back(x);
        }
    }

    printMatrix(mx);
    cout << "The need matrix : " << endl;
    for (int i = 0; i < processNumber; i++) {
        // cout << "Max for process p" << i + 1 << endl;

        for (int j = 0; j < resourceNumber; j++) {
            need[i].push_back(mx[i][j] - allocation[i][j]);
        }
    }

    printMatrix(need);

    vector<int> available(resourceNumber, 0);

    for (int i = 0; i < resourceNumber; i++) {
        // cout << "Max for process p" << i + 1 << endl;

        int allocated = 0;
        for (int j = 0; j < processNumber; j++) {
            allocated += allocation[j][i];
        }

        available[i] = instances[i] - allocated;
    }

    cout << "Resource currently available " << endl;

    for (int i = 0; i < resourceNumber; i++) {
        cout << available[i] << " ";
    }
    cout << endl;

    cout << "Selection process " << endl;

    int cnt = 0;

    for (int k = 0; k < processNumber; k++) {
        for (int i = 0; i < processNumber; i++) {

            bool canTake = true;
            for (int j = 0; j < resourceNumber; j++) {

                if (need[i][j] == -1 or need[i][j] > available[j]) {
                    canTake = false;
                    break;
                }
            }

            if (canTake) {
              

                cout << "P" << i + 1 << " : ";
                cnt++;
                for (int j = 0; j < resourceNumber; j++) {
                    available[j] += allocation[i][j];
                    need[i][j] = -1;
                }

                for (int j = 0; j < resourceNumber; j++) {
                    cout << available[j] << " ";
                }

                cout << endl;
                  break;
            }
        }
    }

    cout << "Finally available :" << endl;

    for (int j = 0; j < resourceNumber; j++) {
        cout << available[j] << " ";
    }

    if (cnt == processNumber)
        cout << "\nNO DEADLOCK DETECTED " << endl;
    else
        cout << "DEADLOCK" << endl;

    return 0;
}

/*

3 5
15 19 9
3 8 0 
2 0 0
3 0 2
2 1 1
0 1 1
2 1 1

7 9 2
3 2 2
3 3 2
4 2 3
3 3 3
7 9 9

Sample input 

3 5
10 5 7
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2 
9 0 2
2 2 2
4 3 3

Sample output

Enter the allocation matrix : 
p1  0 1 0
p2  2 0 0
p3  3 0 2
p4  2 1 1
p5  0 0 2
Enter the max matrix : 
p1  7 5 3
p2  3 2 2
p3  9 0 2
p4  2 2 2
p5  4 3 3
The need matrix : 
p1  7 4 3
p2  1 2 2
p3  6 0 0
p4  0 1 1
p5  4 3 1
Resource currently available 
3 3 2 
Selection process 
P2 : 5 3 2 
P4 : 7 4 3 
P5 : 7 4 5 
P1 : 7 5 5 
P3 : 10 5 7 
Finally available :
10 5 7 
NO DEADLOCK DETECTED

*/