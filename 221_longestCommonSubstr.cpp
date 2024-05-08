#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[1001][1001];
        // dp[i][j] stores the longest common substring length
        // in s1[0...i-1] and s2[0....j-1]
    
        // if one of strings have length zero, longest common substring
        // will also be of 0 length
        for (int i = 0; i < n; ++i)
            dp[i][0] = 0;
    
        for (int i = 0; i < m; ++i)
            dp[0][i] = 0;
    
        int res = 0; // ans
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                // if current characters are same, we increase the length by 1
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                // else, there's no common substring ending at i - 1 and j - 1
                else
                    dp[i][j] = 0;
    
                res = max (res, dp[i][j]); // storing the answer
            }
        }
        return res;
    }
    


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubstr(s1, s2, s1.size(), s2.size()) << endl;

return 0;
}