#include<bits/stdc++.h>
using namespace std;

// int fib(int n, vector<int>&dp){
//     if(n<=1) 
//     return n;

// //step 3
//     if(dp[n]!=-1){
//         return dp[n];
//     }

// //step2
//     dp[n]= fib(n-1,dp)+fib(n-2,dp);
//     return dp[n];    
// }


int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    //step2
    for(int i=2;i<=n;i++){
        dp[i]= dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;

return 0;
}