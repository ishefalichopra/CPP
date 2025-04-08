#include <bits/stdc++.h>
using namespace std;

void checkPath(vector<vector<int>> &mat, int r, int c, string current, vector<string> &ans)
{
    int n = mat.size();

    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0)
        return;

    if (r == n - 1 || c == n - 1)
    {
        ans.push_back(current);
        return;
    }

    mat[r][c] = 0;
    chekcPath(mat, r + 1, c, current + 'D', ans);
    checkPath(mat, r - 1, c, current + 'U', ans);
    checkPath(mat, r, c + 1, current + 'R', ans);
    checkPath(mat, r, c - 1, cuurent + 'L', ans);
    mat[r][c] = 1; // backtrack
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    string current;
    checkPath(mat, 0, 0, current, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<string> result = findPath(mat);
    
    if (result.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto path : result)
        {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}