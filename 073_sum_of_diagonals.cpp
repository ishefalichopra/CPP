#include<bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution {
  public:
    int diagonalSumDifference(int N, vector<vector<int>> Grid) 
    {
        int sum = 0; 
        int sum1 = 0;
        for(int i = 0; i < N; i++)
        {
            sum += Grid[i][i];
            sum1 += Grid[i][N - i - 1];
        }
        return abs(sum - sum1);
    }
};
int main()
{
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<vector<int>> Grid1 (n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>Grid1[i][j];
        }
        
    }
    Solution ob;
    cout<<ob.diagonalSumDifference(n, Grid1)<<endl;
    
}
return 0;
}