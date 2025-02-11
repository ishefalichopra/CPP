#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int r)
{
    vector<int> temp;
    int ans = 1;
    temp.push_back(1);
    for (int col = 1; col < r; col++)
    {
        ans = ans * (r - col);
        ans = ans / col;
        temp.push_back(ans);
    }
    return temp;
}

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = pascalTriangle(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}