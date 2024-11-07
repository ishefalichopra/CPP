#include <bits/stdc++.h>
using namespace std;

int countZeroes(const string &strs)
{
    return count(strs.begin(), strs.end(), '0');
}

int countOnes(const string &strs)
{
    return count(strs.begin(), strs.end(), '1');
}

// int dfs(vector<string>& strs, int i, int m, int n) {
//     // Base case: If we have checked all strings
//     if (i == strs.size())
//         return 0;

//     int zeroes = countZeroes(strs[i]);
//     int ones = countOnes(strs[i]);

//     // Option 1: Skip the current string
//     int skip = dfs(strs, i + 1, m, n);

//     // Option 2:Take the current string if it fits
//     int take = 0;
//     if (m >= zeroes && n >= ones) {
//         take = 1 + dfs(strs, i + 1, m - zeroes, n - ones);
//     }
//     return max(skip, take);
// }

int dfsMemo(vector<string> &strs, int m, int n, vector<vector<int>> &dp)
{
    for (const auto &str : strs)
    {
        int zeroes = countZeroes(str);
        int ones = countOnes(str);

        for (int j = m; j >= zeroes; --j)
        {
            for (int k = n; k >= ones; --k)
            {
                dp[j][k] = max(dp[j][k], 1 + dp[j - zeroes][k - ones]);
            }
        }
    }
    return dp[m][n];
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    return dfsMemo(strs, m, n, dp);
}
int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << findMaxForm(strs, m, n) << endl;
    return 0;
}