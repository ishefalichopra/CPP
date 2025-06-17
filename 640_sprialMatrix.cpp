#include<bits/stdc++.h>
using namespace std;

vector<int> sprialMatrix(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> result;

    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int idx = 1;
    int i = 0, j = 0;
    int d = 0;

    result.push_back(matrix[0][0]);
    matrix[0][0] = -101;

    while(idx < (m*n)){
        int x = i + dir[d%4][0];
        int y = j + dir[d%4][1];
        if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != -101){
            result.push_back(matrix[x][y]);
            matrix[x][y] = -101;
            i = x;
            j = y;
            idx++;
        } else {
            d++;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sprialMatrix(matrix);

    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

return 0;
}