#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> transposed(m, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> result = transpose(matrix);

    for(const auto& row : result){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

return 0;
}