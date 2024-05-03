#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> li, li2;

   
    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        li.push_back(k);
    }

    li2 = li;
    sort(li2.begin(), li2.end());

    for(auto u : li2)
        cout << u << " ";


    cout << endl;
    cout << "Enter the size of your request: ";
    int size; cin >> size;

   
    cout << "1. First-fit" << endl;
    cout << "2. Best-fit" << endl;
    cout << "3. Worst-fit" << endl;
    cout << "Option: ";
    int option; cin >> option;

    if(option == 1)
    {
        for(int i = 0; i < n; i++)
        {
            if(li[i] >= size)
            {
                cout << li[i] << endl;
                li[i] -= size;
                break;
            }
        }
    }
    else if(option == 2)
    {
        for(int i = 0; i < n; i++)
        {
            if(li2[i] >= size)
            {
                cout << li2[i] << endl;
                li2[i] -= size;
                break;
            }
        }
    }
    else
    {
        cout << li2[n-1] << endl;
        li2[n-1] -= size;             
    }

    return 0;
}

// 5
// 10 2 4 5 8