#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;

    //Take the number of processes
    cout << "Enter no. of threads: ";
    cin >> n;

    //Take the number of instances for each process, here number of process have been fixed to 3
    int A, B, C;
    cout << "Enter the instances for three process: ";
    cin >> A >> B >> C;

    //Declare the necessary matrix and vectors
    int allocation[n][3], maxi[n][3], need[n][3];
    int sumA = 0, sumB = 0, sumC = 0;
    int available[3], work[3], sequence[n];
    bool finish[n];

    //Take input for the allocation and max matrices

    cout << "Enter the allocation matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the maximum matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> maxi[i][j];
        }
    }


    //Calculating the available instances of each resource
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

    available[0] = (A-sumA);
    available[1] = (B-sumB);
    available[2] = (C-sumC);

   
    //Calculating the need matrix using need = max - allocation 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            need[i][j] = maxi[i][j] - allocation[i][j];
        }
    }

    //Start of bankers algorithm

    // Define work to be equal to available array
    for(int i = 0; i < 3; i++)
    {
        work[i] = available[i];
    }

    //Declare all finish 0 -> n-1, to be false
    for(int i = 0; i < n; i++)
    {
        finish[i] = false;
    }

    int count = 0, index = 0, ck, p = 0;

    //Find and an index such that finish[index] = false and need <= work 
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
                sequence[p] = index;
                p++;

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

        index++;
        if(index == n)
            index = 0;
    }

    bool f = true;

    //Check if all the elements of the finish array is true or not
    for(int i = 0; i < n; i++)
    {
        if(!finish[i])
        {
            f = false;
            break;
        }
    }

    //If all are true then no deadlock occurs and a safe sequence is produced else goes to unsafe state
    if(f)
    {
        cout << endl;
        cout << "No deadlock. The safe sequence is: " << endl;
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
        cout << "Deadlock detected. System does not grant permission as safe state was not found." << endl;
    }




    return 0;
}

/*
Sample Input
5
 
10 5 7
 
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
 
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
*/