#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr)
{
    // code here
    int n = arr.size();
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int jumps = 0;
    int x = 0; // current range
    int y = 0; // current reachable point

    for (int i = 0; i < n - 1; i++)
    {
        y = max(y, arr[i] + i); // reachable

        if (i == x)
        {
            jumps++;
            x = y;

            if (x >= n - 1)
            {
                return jumps;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minJumps(arr) << endl;

    return 0;
}