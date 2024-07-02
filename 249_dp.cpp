#include <bits/stdc++.h>
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
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;
    // step2
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;

    return 0;
}