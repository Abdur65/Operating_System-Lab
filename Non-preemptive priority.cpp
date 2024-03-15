#include <bits/stdc++.h>
using namespace std;

void nonpreemp_prior()
{
    cout << "Enter no. of process: ";
    int n; cin >> n;

    vector<int> burst, priori, proc;
    int a, b;

    //Input for burst and priority
    cout << "\tBurst\tPriority";
    for(int i = 0; i < n; i++)
    {
       cout << "Process " << i+1 << ": ";
       cin >> a;
       cout << "\t";
       cin >> b;
       burst.push_back(a);
       priori.push_back(b);
       proc.push_back(i+1);
    }

    //For sorting the processes according to the priorities
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(priori[i] > priori[j])
            {
                swap(proc[i], proc[j]);
                swap(burst[i], burst[j]);
                swap(priori[i], priori[j]);
            }
        }
    }

    //Gantt chart
    cout << "Gantt chart for the processes - " << endl;
    for(int i = 0; i < n; i++)
    {
        if(i != n-1)
            cout << "| P" << proc[i] << " ";
        else
            cout << "| P" << proc[i] << "|";
    }

    cout << endl;

    //Calculating the waiting time for the proceses
    vector<int> wait;
    int sum = 0;
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
        cout << wait[i];
        cout << endl;
    }

    //Calculating the average waiting time
    float avg;
    avg = float(sum/n);

    cout << "The average waiting time for the processe is " << avg;
    cout << endl;



}

int main()
{

    nonpreemp_prior();

    return 0;
}