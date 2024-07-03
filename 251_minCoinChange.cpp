#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int>&num, int x)
{
    vector<int>dp(x+1,INT_MAX);//bottom up approach
    dp[0]=0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
            dp[i]= min(dp[i],1+dp[i-num[j]]);
        }
    }

    if(dp[x]==INT_MAX)
    return -1;

    return dp[x];

}

int main()
{
    vector<int>num={1,2,5};
    int x=11;
    cout<<solveTab(num,x)<<endl;

return 0;
}