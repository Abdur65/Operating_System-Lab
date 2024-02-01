// C213031
#include <bits/stdc++.h>
using namespace std;

void FCFS()
{
    cout << "Enter no. of process ";
    int n; cin >> n;

    vector<int> v;
    int k;

    for(int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i+1 << ": ";
        cin >> k;
        v.push_back(k);
    }

    //sort(v.begin(), v.end());

    vector<int> wait;
    wait.push_back(0);
    int sum = 0, sum1 = 0;

    for(int i = 0; i < n; i++)
    {

        sum += v[i];
        wait.push_back(sum);
    }

    for(int i = 0; i < n; i++)
    {
        cout << "Waiting time for process " << i+1 << " is " << wait[i];
        cout << endl;
        sum1 += wait[i];
    }


    cout << "The average waiting for the processes is " << sum1/n;
}

int main()
{
    FCFS();
    
    return 0;
}





