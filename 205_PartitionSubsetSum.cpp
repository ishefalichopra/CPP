#include<bits/stdc++.h>
using namespace std;

bool equalPartitionHelper(int arr[],int N, int index, int targetSum, int currentSum,vector<vector<int>>&dp) {
        if (currentSum == targetSum)
            return 1;
        if(currentSum>targetSum || index>=N)
            return 0; 
        if(dp[index][currentSum]!=-1)
            return dp[index][currentSum];
    
        dp[index][currentSum] = equalPartitionHelper(arr,N, index + 1, targetSum, currentSum,dp) ||
               equalPartitionHelper(arr,N, index + 1, targetSum, currentSum + arr[index],dp);
       
       return dp[index][currentSum];
    }
    int equalPartition(int N, int arr[])
    { 
        int totalSum = 0;
        for (int i=0;i<N;i++)
            totalSum += arr[i];
    
        if (totalSum % 2 != 0)
            return 0; 
        int targetSum = totalSum/2;
        vector<vector<int>>dp(N,vector<int>(targetSum +1, -1)); 
        return equalPartitionHelper(arr,N, 0, targetSum, 0,dp); 
    }

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    cout << equalPartition(n,a) << endl;    

return 0;
}