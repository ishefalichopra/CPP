#include <bits/stdc++.h>
using namespace std;

int flippingMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size() / 2;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += max({matrix[i][2 * n - 1 - j],
                        matrix[2 * n - 1 - i][j],
                        matrix[i][j],
                        matrix[2 * n - 1 - i][2 * n - 1 - j]});
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(2 * n, vector<int>(2 * n));
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int result = flippingMatrix(matrix);
    cout << result << endl;

    return 0;
}