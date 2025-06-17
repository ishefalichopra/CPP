#include<bits/stdc++.h>
using namespace std;

void rotate180(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for(int j=0;j<m;j++){
        int top = 0, bottom = n-1;
        while(top < bottom){
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }

}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate180(matrix);

    for(const auto& row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

return 0;
}