#include <bits/stdc++.h>
using namespace std;

// void setZeroes(vector<vector<int>>& matrix){
//     int n = matrix.size();
//     int m = matrix[0].size();

//     unordered_set<int> row, col;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(matrix[i][j] == 0){
//                 row.insert(i);
//                 col.insert(j);
//             }
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(row.count(i) || col.count(j)){
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            flag = true;

        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (flag)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    setZeroes(matrix);

    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}