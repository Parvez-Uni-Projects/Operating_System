#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl "\n"

int32_t main()
{

    FAST;

    int numberOfProcesses, numberOfResources;

    cout << "Enter the number of processes: ";
    cin >> numberOfProcesses;

    cout << endl;

    cout << "Enter the number of resources: ";
    cin >> numberOfResources;
    cout << endl;

    int totalResources[numberOfResources];

    cout << "Enter the total number of resources: ";
    for (int i = 0; i < numberOfResources; i++)
    {
        cin >> totalResources[i];
    }

    cout << endl;

    int allocated[numberOfProcesses][numberOfResources];

    cout << "Enter the allocated resources: ";


    // it is the resources that are allocated to the processes
    for (int i = 0; i < numberOfProcesses; i++)
    {
        for (int j = 0; j < numberOfResources; j++)
        {
            cin >> allocated[i][j];
        }
    }

    cout << endl;

    int needed[numberOfProcesses][numberOfResources];

    cout << "Enter the needed resources: ";
    
    // it is the resources that are needed by the processes
    for (int i = 0; i < numberOfProcesses; i++)
    {
        for (int j = 0; j < numberOfResources; j++)
        {
            cin >> needed[i][j];
        }
    }

    cout << endl;

    int maximum[numberOfProcesses][numberOfResources];

    // it is the sum of allocated and needed resources
    for (int i = 0; i < numberOfProcesses; i++)
    {
        for (int j = 0; j < numberOfResources; j++)
        {
            maximum[i][j] = allocated[i][j] + needed[i][j];
        }
    }

    

    cout << "Maximum resources: " << endl;
    for (int i = 0; i < numberOfProcesses; i++)
    {
        for (int j = 0; j < numberOfResources; j++)
        {
            cout << maximum[i][j] << " ";
        }
        cout << endl;
    }


    vector<int> available(numberOfResources);

    // it is total resources - allocated resources
    for (int i = 0; i < numberOfResources; i++)
    {
        int sum = 0;
        for (int j = 0; j < numberOfProcesses; j++)
        {
            sum += allocated[j][i];
        }
        available[i] = totalResources[i] - sum;
    }

    cout << "Available resources: " << endl;

    for (int i = 0; i < numberOfResources; i++)
    {
        cout << available[i] << " ";
    }

    cout << endl;

    vector<bool> finish(numberOfProcesses, false);



    int safeSequence[numberOfProcesses];
    int index = 0;
    auto work = available;
    
    while (index < numberOfProcesses)
    {
        bool flag = false;

        for (int i = 0; i < numberOfProcesses; i++)
        {
            if (finish[i] == false)
            {
                int j;
                for (j = 0; j < numberOfResources; j++)
                {
                    if (needed[i][j] > work[j])
                    {
                        break;
                    }
                }

                if (j == numberOfResources)
                {
                    safeSequence[index++] = i;
                    finish[i] = true;
                    flag = true;

                    for (int k = 0; k < numberOfResources; k++)
                    {
                        work[k] += allocated[i][k];
                    }
                }
            }
        }

        if (flag == false)
        {
            break;
        }
    }

    if (index != numberOfProcesses)
    {
        cout << "The system is not in a safe state" << endl;
    }
    else
    {
        cout << "The system is in a safe state" << endl;
        cout << "Safe sequence: ";

        for (int i = 0; i < numberOfProcesses; i++)
        {
            cout << safeSequence[i] +1 << " ";
        }
    }

    return 0;
}