#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int areMatricesIdentical(int N, vector<vector<int>> Grid1, vector<vector<int>> Grid2)
    {
        bool check = true;
        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < N; j++)
            {
                if (Grid1[i][j] != Grid2[i][j])
                {
                    return 0;
                }
                else
                    continue;
            }
        }
        return 1;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> Grid1(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>Grid1[i][j];
            }
        }
        vector<vector<int>> Grid2(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>Grid2[i][j];
            }
        }
        Solution ob;
        cout<<ob.areMatricesIdentical(n,Grid1,Grid2)<<endl;
    }
    return 0;
}