#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    vector<vector<int, int>> allocation, maxi, need;
    int A = 10, B = 5, C = 7;
    int sumA, sumB, sumC;
    vector<int> available, work, sequence;
    vector<bool> finish;

    cout << "Enter no. of threads: ";
    cin >> n;

    //The allocation matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int k; cin >> k;
            allocation[i].push_back(k);
        }
    }

    //The max matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int k; cin >> k;
            maxi[i].push_back(k);
        }
    }

    //Calculating available vector
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                sumA += allocation[i][j];
            }
            else if(j == 1)
            {
                sumB += allocation[i][j];
            }
            else
            {
                sumC += allocation[i][j];
            }
        }
    }

    available.push_back(A-sumA);
    available.push_back(B-sumB);
    available.push_back(C-sumC);

    //Calculating the need matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            need[i].push_back(maxi[i][j] - allocation[i][j]);
        }
    }

    work = available;

    for(int i = 0; i < n; i++)
    {
        finish.push_back(false);
    }

    int count = 0, index = 0, ck;

    while(count != n)
    {
        if(finish[index] == true)
        {
            count++;
        }
        else
        {
            ck = 0;
            for(int i = 0; i < 3; i++)
            {
                if(need[index][i] <= work[i])
                    ck++;
            }
            
            if(ck == 3)
            {
                finish[index] = true;
                sequence.push_back(index);

                for(int i = 0; i < 3; i++)
                {
                    work[i] = work[i] + allocation[index][i];
                }

                count = 0;
            }
            else
            {
                count++;
            }
        }
        if(index++ == n)
            index = 0;
        else
            index++;

    }

    bool f = true;

    for(int i = 0; i < n; i++)
    {
        if(!finish[i])
        {
            f = false;
            break;
        }
    }

    if(f)
    {
        cout << "<";
        for(int i = 0; i < n; i++)
        {
            cout <<  "P" <<  sequence[i];
            if(i != n-1) cout << ", ";
        }
        cout << ">";
    }
    else
    {
        cout << "System does not grant permission as safe state was not found.";
    }






    return 0;
}