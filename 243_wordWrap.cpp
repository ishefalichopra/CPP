#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[505][2005];
    int rec(int level, int left, int n, int k,vector<int>&nums)
    {
        if(level==n)
        {
            return 0;
        }

        if(dp[level][left]!=-1)
        {
            return dp[level][left];
        }
        int ans=1e9;
        if(nums[level]>left)
        {
            ans=min(ans,rec(level+1,k-nums[level]-1,n,k,nums)+(left+1)*(left+1));
        }
        else
        {
            ans=min(ans,rec(level+1,left-nums[level]-1,n,k,nums));
            ans=min(ans,rec(level+1,k-nums[level]-1,n,k,nums)+(left+1)*(left+1));
        }
        return dp[level][left]=ans;
           
        
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int p=rec(0,k,n,k,nums);
        return p;
        
    } 
};


//{ Driver Code Starts.
int main(){
	
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	
	return 0;
}
