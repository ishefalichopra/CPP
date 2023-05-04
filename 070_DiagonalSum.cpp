#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int DiagonalSum(vector<vector<int>> & matrix){
    int d1=0, d2=0;
    int m= matrix.size()-1;
    for(int i=0;i< matrix.size(); i++){
        d1 = d1+ matrix[i][i];
        d2 = d2+ matrix[i][m];
        m--;
    }
    return (d1+d2);
}
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
       
        vector<vector<int>> matrix (n, vector <int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        int ans = ob.DiagonalSum(matrix);
        cout<<ans<<endl;
    }


return 0;
}