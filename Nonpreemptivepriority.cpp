#include <bits/stdc++.h>
using namespace std;

void nonpreemp_prior()
{
    cout << "Enter no. of process: ";
    int n; cin >> n;

    vector<int> burst, priori, proc;
    int a, b;

    //Input for burst and priority
    cout << "\tBurst Priority" << endl;
    for(int i = 0; i < n; i++)
    {
       cout << "Process " << i+1 << ": ";
       cin >> a >> b;
       burst.push_back(a);
       priori.push_back(b);
       proc.push_back(i+1);
    }

    //For sorting the processes according to the priorities
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(priori[j] > priori[j+1])
            {
                swap(proc[j+1], proc[j]);
                swap(burst[j+1], burst[j]);
                swap(priori[j+1], priori[j]);
            }
        }
    }

    for(auto u : priori) cout << u << " ";
    cout << endl;

    //Gantt chart
    cout << "Gantt chart for the processes - " << endl;
    for(int i = 0; i < n; i++)
    {
        if(i != n-1)
            cout << "| P" << proc[i] << " ";
        else
            cout << "| P" << proc[i] << " |";
    }

    cout << endl;

    //Calculating the waiting time for the proceses
    vector<int> wait;
    int sum = 0;
    float sum2 = 0;
    wait.push_back(sum);

    for(int i = 0; i < n-1; i++)
    {
        sum += burst[i];
        wait.push_back(sum);
    }

    //Displaying waiitng times for each proceses
    for(int i = 0; i < n; i++)
    {
        cout << "Waitng time for P" << i+1 << ": ";
        sum2 += wait[i];
        cout << wait[i];
        cout << endl;
    }

    //Calculating the average waiting time
    float avg;
    avg = float(sum2/n);

    cout << "The average waiting time for the processe is " << avg;
    cout << endl;



}

int main()
{

    nonpreemp_prior();

    return 0;
}