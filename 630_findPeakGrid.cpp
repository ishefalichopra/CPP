#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int left = 0, right = n - 1;

    while (left <= right)
    {
        int midCol = (left + right) / 2;
        int maxRow = 0;

        for (int i = 0; i < m; i++)
        {
            if (mat[i][midCol] > mat[maxRow][midCol])
            {
                maxRow = i;
            }
        }

        int curr = mat[maxRow][midCol];
        int leftVal = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
        int rightVal = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

        if (curr > leftVal && curr > rightVal)
        {
            return {maxRow, midCol};
        }
        else if (leftVal > curr)
        {
            right = midCol - 1;
        }
        else
        {
            left = midCol + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {1, 4, 3, 2},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<int> peak = findPeakGrid(mat);
    cout << "Peak found at: (" << peak[0] << ", " << peak[1] << ")" << endl;

    return 0;
}