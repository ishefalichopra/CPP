#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size();
    int cntCows = 1, last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int cows)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(stalls, mid, cows) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9};
    cout << aggressiveCows(stalls, 3) << endl;

    return 0;
}