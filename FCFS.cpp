// C213031
#include <bits/stdc++.h>
using namespace std;

void FCFS()
{
    //Input no. of process
    cout << "Enter no. of process ";
    int n; cin >> n;

    vector<int> v;
    int k;

    //Input the burst time for each process
    for(int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i+1 << ": ";
        cin >> k;
        v.push_back(k);
    }

    
    //vector to store the waiting time for each process
    vector<int> wait;
    wait.push_back(0);
    int sum = 0, sum1 = 0;

    //calculate the waiting time for each process
    for(int i = 0; i < n; i++)
    {
        sum += v[i];
        wait.push_back(sum);
    }

    //Gantt chart
    for(int i = 0; i < n; i++)
    {
        if(i != n-1)
        {
            cout << "| P" << i+1 << " "; 
        }
        else
        {
            cout << "| P" << i+1 << " |";
        }
    }

    cout << endl;
    cout << "Waiting times - " << endl;

    // Display waiting time of each process
    for(int i = 0; i < n; i++)
    {
        cout << "Waiting time for process " << i+1 << " is " << wait[i];
        cout << endl;
        sum1 += wait[i];
    }

    //The average time for n processes
    cout << "The average waiting for the processes is " << sum1/n;
}

int main()
{
    FCFS();
    
    return 0;
}





