#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];

    int a = solveMem(n - x, x, y, z, dp) + 1;
    int b = solveMem(n - y, x, y, z, dp) + 1;
    int c = solveMem(n - z, x, y, z, dp) + 1;

    return dp[n] = max(a, max(b, c));
}

int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);

        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;

    else
        return dp[n];
}

int cutIntoSegments(int n, int x, int y, int z)
{
    // return solve(n,x,y,z);
    // vector<int> dp(n+1,-1);
    // return solveMem(n,x,y,z,dp);
    return solveTab(n, x, y, z);
}

int main()
{
    int n = 5, x = 5, y = 3, z = 2;
    cout << cutIntoSegments(n, x, y, z) << endl;

    return 0;
}