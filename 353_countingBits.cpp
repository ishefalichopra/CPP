#include <bits/stdc++.h>
using namespace std;

// Brute Force
//  int count(string i) {
//      int cnt = 0;
//      for (int k = 0; k < i.size(); k++) {
//          if (i[k] == '1') {
//              cnt++;
//          }
//      }
//      return cnt;
//  }
//  vector<int> countBits(int n) {
//      vector<int> ans;
//      for (int i = 0; i <= n; i++) {

//         ans.push_back(count(bitset<8>(i).to_string()));
//     }
//     return ans;
// }

// Recursion

// int countBitsRecursive(int i) {
//     if (i == 0)
//         return 0;
//     return countBitsRecursive(i >> 1) + (i & 1);
// }

// Memoization

// int countBitsMemo(int i, vector<int>& dp) {
//     if (i == 0) {
//         return 0;
//     }
//     if (dp[i] != -1)
//         return dp[i];

//     dp[i] = countBitsMemo(i >> 1, dp) + (i & 1);

//     return dp[i];
// }

// Tabulation

// vector<int> countBits(int n) {
//     vector<int> dp(n + 1, 0);
//     for (int i = 1; i <= n; i++) {
//         dp[i] = dp[i >> 1] + (i & 1);
//     }
//     return dp;
// }

// Space Optimization

vector<int> countBits(int n)
{
    vector<int> result(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}

int main()
{
    int n = 5;
    vector<int> ans = countBits(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}