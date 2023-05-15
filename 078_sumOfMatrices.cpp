#include<bits/stdc++.h>
using namespace std;
//User function Template for C++

class Solution {
public:
    void Addition(vector<vector<int> >& matrixA, vector<vector<int>>&matrixB) {
        int n=matrixA.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrixA[i][j]=matrixA[i][j]+matrixB[i][j];
            }
        }
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrixA(n,vector<int>(n,0));
    vector<vector<int>> matrixB(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrixA[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrixB[i][j];
        }
    }

    Solution ob;
    ob.Addition(matrixA,matrixB);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrixA[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}