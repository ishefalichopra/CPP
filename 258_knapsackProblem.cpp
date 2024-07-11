#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int>&weight, vector<int>&value, int index, int capacity, vector<vector<int>>&dp){
   if(index==0){
    if(weight[0]<=capacity)
    return value[0];
    else
    return 0;
   }

    if(dp[index][capacity]!=-1)
    return dp[index][capacity];

    int include=0;
    if(weight[index]<=capacity)
    {
        include=value[index]+solveMem(weight, value, index-1, capacity-weight[index], dp);

        int exclude = solveMem(weight, value, index-1, capacity, dp);

        dp[index][capacity]=max(include, exclude);

    }
    return dp[index][capacity];
}

int solveTab(vector<int>&weight, vector<int>&value, int n, int capacity){
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=w)
        dp[0][w]=value[0];
        else
        dp[0][w]=0;
    }

    for(int index=1;index<n;index++){
        for(int w=1;w<=capacity;w++){
            int include=0;
            if(weight[index]<=w)
            {
                include=value[index]+dp[index-1][w-weight[index]];

                int exclude = dp[index-1][w];

                dp[index][w]=max(include, exclude);

            }
            else
            dp[index][w]=dp[index-1][w];
        }
    }
    return dp[n-1][capacity];
}

int solveSO(vector<int>&weight, vector<int>&value, int n, int capacity){
    vector<int> prev(capacity+1,0);
   

    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity)
        prev[w]=value[0];
        else
        prev[w]=0;
    }

    for(int index=1;index<n;index++){
        for(int w=capacity;w>=1;w--){
            int include=0;
            if(weight[index]<=w)
            {
                include=value[index]+prev[w-weight[index]];

                int exclude = prev[w];

              prev[w]=max(include, exclude);

            }
        }
    }
    return prev[capacity];
}

int knapsack(vector<int>&weight, vector<int>&value,int n, int capacity){
    // vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

    // return solveMem(weight, value, weight.size()-1, capacity, dp);

    // return solveTab(weight, value, n, capacity);

    return solveSO(weight, value, n, capacity);
}



int main()
{
    vector<int> weight={10, 20, 30};
    vector<int> value={60, 100, 120};
    int n=3;
    int capacity=50;

    cout<<knapsack(weight, value, n, capacity)<<endl;

return 0;
}