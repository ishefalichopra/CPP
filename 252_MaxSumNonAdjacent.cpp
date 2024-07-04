#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    if(n<0){
        return 0;
    }

    if(n==0)
    return nums[0];

    int incl= solve(nums,n-2)+nums[n];
    int excl= solve(nums,n-1);

    return max(incl,excl);
}

int solveMem(vector<int>&nums, int n, vector<int>&dp){
    if(n<0){
        return 0;
    }

    if(n==0)
    return nums[0];

    if(dp[n]!=-1)
    return dp[n];

    int incl= solveMem(nums,n-2,dp)+nums[n];
    int excl= solveMem(nums,n-1,dp);

    return dp[n]=max(incl,excl);
}

int solveTab(vector<int>&nums){

    int n=nums.size();
   vector<int>dp(n,0);
    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int incl= dp[i-2]+nums[i];
        int excl= dp[i-1];

        dp[i]=max(incl,excl);
    }

    return dp[n-1];
}

int solveSO(vector<int>&nums, int n){
    int prev2=0;
    int prev1=nums[0];

    for(int i=1;i<n;i++){
        int incl= prev2+nums[i];
        int excl= prev1;

        prev2=prev1;
        prev1=max(incl,excl);
    }
    return prev1;
}



int MaxSumOfNonAdjacentElements(vector<int>&nums, int n){

   
   return solveSO(nums,n-1);
    

}

int main()
{

    vector<int>nums={9,9,8,2};
    int n=nums.size();
    cout<<MaxSumOfNonAdjacentElements(nums,n)<<endl;
return 0;
}