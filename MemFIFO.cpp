#include <bits/stdc++.h>
using namespace std;

vector<int> refString{7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};

// FIFO algorithm for page demand
void FIFO()
{   
    int frameSize = 1;

    while(frameSize != 8)
    {
        vector<int> frames(frameSize, -1);
        int pageFault = 0;
        int p = 0;
        for(int i = 0; i < refString.size(); i++)
        {
            if(find(frames.begin(), frames.end(), refString[i]) == frames.end())
            {
                pageFault++;
                frames[p] = refString[i];
                p++;
                if(p == frameSize)
                    p = 0;
                
            }
        }

        cout << "For " << frameSize << " frames there are " << pageFault << " page faults." << endl;

        frameSize++;

    }

}

// Optimal algorithm for page demand
void Optimal()
{
    int frameSize = 1;

    while(frameSize != 8)
    {
        vector<int> frames(frameSize, -1);
        int pageFault = 0;
        int p = 0;
        for(int i = 0; i < refString.size(); i++)
        {
            vector<bool> visitedPage(100, false);
            if(find(frames.begin(), frames.end(), refString[i]) == frames.end())
            {
                pageFault++;
                if(i < frameSize)
                {
                    frames[i] = refString[i];
                }
                else
                {
                    int lastPage;
                    vector<bool> visitedPage(100, false);
                    for(int j = i; j < refString.size(); j++)
                    {
                        if(visitedPage[frames[j]] == false)
                        {
                            lastPage = j;
                            visitedPage[frames[j]] = true;
                        }
                    }
                    frames[lastPage] = refString[i];
                }
            }
        }

        cout << "For " << frameSize << " frames there are " << pageFault << " page faults." << endl;

        frameSize++;

    }
}

int main()
{
    Optimal();
    FIFO();
    return 0;
}