#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> mat(n, vector<int>(n, 0));

    vector<vector<int>> v = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int i = 0, j = 0, idx = 1;
    int d = 0;
    mat[0][0] = idx++;
    while (idx <= (n * n))
    {
        int a = i + (v[d % 4][0]);
        int b = j + (v[d % 4][1]);
        if (a >= 0 && a < n && b >= 0 && b < n && mat[a][b] == 0)
        {
            i = a;
            j = b;
            mat[i][j] = idx;
            idx++;
        }
        else
        {
            d++;
        }
    }
    return mat;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> result = generateMatrix(n);

    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}