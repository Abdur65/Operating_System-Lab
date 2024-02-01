// C213031
#include <bits/stdc++.h>
using namespace std;

void SJF()
{
    cout << "Enter no. of process ";
    int n; cin >> n;

    map<int, int> mp;
    vector<int> v;
    int k;

    for(int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i+1 << ": ";
        cin >> k;
        v.push_back(k);
        mp[k] = i+1;
    }

    sort(v.begin(), v.end());

    vector<int> wait;
    wait.push_back(0);
    int sum2 = 0, sum3 = 0;

     for(int i = 0; i < n; i++)
     {
         sum2 += v[i];
         wait.push_back(sum2);
     }

     cout << "The order of process: ";

     for(int i = 0; i < n; i++)
     {
        cout << mp[v[i]] << " -> ";
     }

     cout << endl;

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