#include <bits/stdc++.h>
using namespace std;

int knightDialer(int n)
{
    const int MOD = 1e9 + 7;
    vector<vector<int>> moves = {
        {4, 6},    // 0
        {6, 8},    // 1
        {7, 9},    // 2
        {4, 8},    // 3
        {0, 3, 9}, // 4
        {},        // 5(no moves)
        {0, 1, 7}, // 6
        {2, 6},    // 7
        {1, 3},    // 8
        {2, 4}     // 9
    };

    vector<vector<int>> dp(n, vector<int>(10, 0));

    // Base Case
    for (int j = 0; j < 10; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dp[i][j] = 0;
            for (int neighbours : moves[j])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][neighbours]) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 0; j < 10; j++)
    {
        result = (result + dp[n - 1][j]) % MOD;
    }
    return result;
}

int main()
{
    int n = 3;
    cout << knightDialer(n) << endl;
    return 0;
}