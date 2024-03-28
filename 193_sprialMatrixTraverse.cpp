#include<bits/stdc++.h>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>>matrix, int r, int c){
    int top=0, bottom=r-1, right=c-1, left=0;
    vector<int>ans;

    while(left<=right&&top<=bottom){

        for(int i=top;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=right;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    int r,c;
    cin >> r >> c;
    vector<vector<int>>matrix(r,vector<int>(c));
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin >> matrix[i][j];
        }
    }
    vector<int>ans=spiralTraverse(matrix,r,c);
    for(auto x:ans){
        cout << x << " ";
    }
    cout << endl;

return 0;
}