// C213031
#include <bits/stdc++.h>
using namespace std;

void SJF()
{
    //Input no. of process
    cout << "Enter no. of process ";
    int n; cin >> n;

    map<int, int> mp;
    vector<int> v;
    int k;

    //Input the burst time for each process
    for(int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i+1 << ": ";
        cin >> k;
        v.push_back(k);
        mp[k] = i+1;
    }

    // Sort the process according to their waiting times
    sort(v.begin(), v.end());

    //vector to store the waiting time for each process
    vector<int> wait;
    wait.push_back(0);

    int sum2 = 0, sum3 = 0;

     for(int i = 0; i < n; i++)
     {
         sum2 += v[i];
         wait.push_back(sum2);
     }

    //Gantt chart
     cout << "The Gantt chart is as follows - " << endl;
     for(int i = 0; i < n; i++)
     {
        if(i != n-1)
            cout << "| P" << mp[v[i]] << " ";
        else
            cout << "| P" << mp[v[i]] << "|";
     }

     cout << endl;

    // Display waiting time of each process
     for(int i = 0; i < n; i++)
     {
         cout << "Waiting time for process " << mp[v[i]] << " is " << wait[i] << endl;
         sum3 += wait[i];
     }

     cout << "The average waiting time is " << sum3/n;

}

int main()
{
    SJF();

    return 0;
}