#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &start, int d, long long minDiff)
{
    int n = start.size();
    long long lastChosen = start[0];

    for (int i = 1; i < n; i++)
    {
        if (lastChosen + minDiff <= start[i] + d)
        {
            lastChosen = max(lastChosen + minDiff, (long long)start[i]);
        }

        else
        {
            return false;
        }
    }
    return true;
}

int maxPossibleScore(vector<int> &start, int d)
{
    int n = start.size();

    sort(start.begin(), start.end());

    int left = 0;
    int right = start[n - 1] - start[0];
    int best = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (isPossible(start, d, mid))
        {
            best = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return best;
}

int main()
{
    vector<int> start = {1, 2, 3, 4, 5};
    int d = 2;
    cout << maxPossibleScore(start, d);

    return 0;
}