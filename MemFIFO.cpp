#include <bits/stdc++.h>
using namespace std;

vector<int> refString{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

// FIFO algorithm for page demand
void FIFO()
{
    int frameSize = 1;

    while (frameSize != 8)
    {
        vector<int> frames(frameSize, -1);
        int pageFault = 0;
        int p = 0;
        for (int i = 0; i < refString.size(); i++)
        {
            if (find(frames.begin(), frames.end(), refString[i]) == frames.end())
            {
                pageFault++;
                frames[p] = refString[i];
                p++;
                if (p == frameSize)
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

    while (frameSize < 8)
    {
        vector<int> frames(frameSize, -1);
        int pageFault = 0;
        int xy = 0;
        for (int i = 0; i < refString.size(); i++)
        {
            if (find(frames.begin(), frames.end(), refString[i]) == frames.end())
            {
                pageFault++;
                if (i < frameSize or xy < frameSize)
                {
                    frames[xy] = refString[i];
                    xy++;
                }
                else
                {
                    int lastPage;
                    int pl = 1;
                    vector<bool> visitedPage(100, false);
                    for (int j = i; j < refString.size(); j++)
                    {
                        if (find(frames.begin(), frames.end(), refString[j]) != frames.end() and visitedPage[refString[j]] == false)
                        {
                            lastPage = refString[j];
                            visitedPage[refString[j]] = true;
                        }
                    }
                    for (int w = 0; w < frameSize; w++)
                    {
                        if (visitedPage[frames[w]] == false)
                        {
                            // cout << 0 << " ";
                            frames[w] = refString[i];
                            pl = 0;
                            break;
                        }
                    }
                    if (pl)
                    {
                        for (int w = 0; w < frameSize; w++)
                        {
                            if (frames[w] == lastPage)
                            {
                                frames[w] = refString[i];
                                break;
                            }
                        }
                    }
                }
            }

            // cout << "xy: " << xy << "---";
            // cout << "PageFault: " << pageFault << " --- ";
            // for (auto u : frames)
            //     cout << u << " ";

            // cout << endl;
        }

        cout << "For " << frameSize << " frames there are " << pageFault << " page faults." << endl;

        frameSize++;
    }
}

void LRU()
{
    int frameSize = 1;

    while (frameSize != 8)
    {
        vector<int> frames(frameSize, -1);
        int pageFault = 0;
        int xy = 0;
        for (int i = 0; i < refString.size(); i++)
        {
            if (find(frames.begin(), frames.end(), refString[i]) == frames.end())
            {
                pageFault++;
                if (i < frameSize or xy < frameSize)
                {
                    frames[xy] = refString[i];
                    xy++;
                }
                else
                {
                    int lastPage;
                    int pl = 1;
                    vector<bool> visitedPage(10, false);
                    for (int j = i-1; j > -1; j--)
                    {
                        if (find(frames.begin(), frames.end(), refString[j]) != frames.end() and visitedPage[refString[j]] == false)
                        {
                            lastPage = refString[j];
                            visitedPage[refString[j]] = true;
                        }
                    }
                    for (int w = 0; w < frameSize; w++)
                    {
                        if (visitedPage[frames[w]] == false)
                        {
                            // cout << 0 << " ";
                            frames[w] = refString[i];
                            pl = 0;
                            break;
                        }
                    }
                    if (pl)
                    {
                        for (int w = 0; w < frameSize; w++)
                        {
                            if (frames[w] == lastPage)
                            {
                                frames[w] = refString[i];
                                break;
                            }
                        }
                    }
                }
            }

            // cout << "PageFault: " << pageFault << " --- ";
            // for (auto u : frames)
            //     cout << u << " ";

            // cout << endl;
        }

        cout << "For " << frameSize << " frames there are " << pageFault << " page faults." << endl;

        frameSize++;
    }
}

int main()
{
    cout << "Optimal";
    Optimal();
    cout << "LRU";
    LRU();

    return 0;
}