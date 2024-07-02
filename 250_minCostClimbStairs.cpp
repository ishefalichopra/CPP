#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    if (dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}

int solve2(vector<int> &cost, int n)
{
    vector<int>dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

int solve3(vector<int>&cost, int n){
    int prev2= cost[0];
    int prev1= cost[1];

    for(int i=2;i<n;i++){
        int curr= cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}



int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans = min(solve3(cost, n - 1), solve3(cost, n - 2));
    return ans;
}

int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}