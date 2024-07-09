#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int solveMem(int n, vector<long long int>&dp){
    if(n==1)
    return 0;

    if(n==2)
    return 1;

    if(dp[n]!=-1)
    return dp[n];

    dp[n]=(((n-1)%mod)* (solveMem(n-1,dp)%mod) + (solveMem(n-2,dp)%mod)%mod);

    return dp[n];
}

long long int solveTab(int n){
    vector<long long int> dp(n+1,-1);
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        long long int first = dp[i-1]%mod;
        long long int second = dp[i-2]%mod;
        long long int sum = (first+second)%mod;
        long long int ans = ((i-1)*sum)%mod;

        dp[i]=ans;
    }

    return dp[n];
}

long long int solveSO(int n){
   
    long long int prev2=0;
    long long int prev1=1;

    for(int i=3;i<=n;i++){
        long long int first = prev1%mod;
        long long int second = prev2%mod;
        long long int sum = (first+second)%mod;
        long long int ans = ((i-1)*sum)%mod;

        prev2=prev1;
        prev1=ans;
    }

    return prev1;
}

long long int countDerangements(int n){
    
    return solveSO(n);
}

int main()
{
    int n;
    cin>>n;
    cout<<countDerangements(n);


return 0;
}