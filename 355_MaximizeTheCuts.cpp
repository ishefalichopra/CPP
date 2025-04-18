#include <bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    // Your code here
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i >= x && dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }

        if (i >= y && dp[i - y] != -1)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }

        if (i >= z && dp[i - z] != -1)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    return dp[n] == -1 ? 0 : dp[n];
}

int main()
{
    int n = 5, x = 5, y = 3, z = 2;
    cout << maximizeTheCuts(n, x, y, z) << endl;

    return 0;
}