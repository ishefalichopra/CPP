#include<bits/stdc++.h>
using namespace std;

int func(string s, string t, vector<vector<int>>&dp, int i, int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) dp[i][j]=func(s,t,dp,i+1,j+1)+func(s,t,dp,i+1,j);
        else dp[i][j]=func(s,t,dp,i+1,j);
        return dp[i][j];

    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(s,t,dp,0,0);

    }

int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    cout<<numDistinct(s,t)<<endl;

return 0;
}