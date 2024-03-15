// C213031
#include <bits/stdc++.h>
using namespace std;

void SRT()
{
    int n, t = 0;
    cin >> n;

    vector<int> arrival(n, 0), burst(n, 0), time(n, 0), pt(n, 0);

    for (auto &x : arrival)
        cin >> x;
    for (auto &x : burst)
        cin >> x;

    priority_queue<pair<pair<int, int>, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({{arrival[i], burst[i]}, i});
    }

    while (!pq.empty())
    {
        t++;
        cout << "P-" << pq.top().second << " ";
        if (time[pq.top().second] != 0)
            pt[pq.top().second] += (t - time[pq.top().second]);
        time[pq.top().second] = t;
        pair<int, int> p = pq.top().first;
        p.second -= 1;
        pq.pop();
        pq.push({{p}, pq.top().second});
        if (p.second == 0)
            pq.pop();
    }

    cout << endl;

    for (auto &x : pt)
        cout << x << ' ';

    cout << endl;

    cout << (double)t / n << endl;

}

int main()
{
    SRT();

    return 0;
}
