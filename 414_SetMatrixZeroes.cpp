#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    int m = matrix.size();
    int n = matrix[0].size();
    bool rFlag = false, cFlag = false;

    for (int j = 0; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            rFlag = true;
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            cFlag = true;
            break;
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (cFlag)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    if (rFlag)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}