#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int sumOfMatrix(int N, int M, vector<vector<int>>Grid){
     int ans=0;
     for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans = ans + Grid[i][j];
        }
     }
     return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N,M;
        cin>>N>>M;
        vector<vector<int>>Grid(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>Grid[i][j];
            }
        }
        Solution ob;
        cout<<ob.sumOfMatrix(N,M,Grid)<<endl;
    }

return 0;
}