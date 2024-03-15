// C213031
#include <bits/stdc++.h>
using namespace std;

void round_robin()
{
    //Input no. of processes
    cout << "Enter no. of process: ";
    int n; cin >> n;

    //Input qunatum no.
    cout << "Enter the time quantum: ";
    int q; cin >> q;

    vector<int> burst, burst2;
    int burst_sum = 0;

    //Input burst times of each process
    for(int i = 0; i < n; i++)
    {
        cout << "Burst time  for process " << i+1 << ":";
        int k; cin >> k;
        burst.push_back(k);
        burst_sum += k;
    }

    burst2 = burst;

    vector<int> proc, wtime;
    int p = 0;
    wtime.push_back(p);

    //Reduce burst time of each process according to the time quantum
    while(burst_sum > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(burst2[i] <= 0)
                continue;

            if(burst2[i] < q)
                p += burst2[i];
            else
                p += q;

            wtime.push_back(p);
            burst2[i] = burst2[i] - q;   
            proc.push_back(i+1);
            burst_sum -= q;
        }
    }

    // cout << endl;
    // cout << proc.size() << endl;

    //Gantt chart
    for(int i = 0; i < proc.size(); i++)
    {
        if(i != proc.size()-1)
            cout << "|    P" << proc[i] << "    ";
        else
            cout << "|    P" << proc[i] << "    |";
    }
    cout << endl;

    //Time elapsed after of each quantum
    for(int i = 0; i < wtime.size(); i++)
    {
        if(wtime[i] < 10)
            cout << wtime[i] << "          ";
        else
           cout << wtime[i] << "         "; 
    }
   

}

int main()
{
    round_robin();


    return 0;
}