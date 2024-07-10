#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int add(int a, int b){
    return (a%mod + b%mod)%mod;
}

int mul(int a, int b){
    return (a%mod * 1LL * b%mod)%mod;
}

int solveMem(int n, int k, vector<int>&dp){
    if(n==1)
    return k;

    if(n==2)
    return add(k, mul(k, k-1));

    if(dp[n]!=-1)
    return dp[n];
    
    dp[n]=add(mul(k-1, solveMem(n-1, k, dp)), mul(k-1, solveMem(n-2, k, dp)));

    return dp[n];
}

int solveTab(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1]=k;
    dp[2]=add(k, mul(k, k-1));

    for(int i=3;i<=n;i++){
        dp[i]=add(mul(k-1, dp[i-1]), mul(k-1, dp[i-2]));
    }

    return dp[n];
}

int solveSO(int n, int k){
    int prev2=k;
    int prev1=add(k, mul(k, k-1));

    for(int i=3;i<=n;i++){
        
        int ans= add(mul(k-1, prev1), mul(k-1, prev2));

        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

int PaintingFence(int n, int k){
    vector<int> dp(n+1, -1);

    return solveSO(n, k);
}


int main()
{
    int n=3, k=2;
    cout<<PaintingFence(n, k)<<endl;

return 0;
}