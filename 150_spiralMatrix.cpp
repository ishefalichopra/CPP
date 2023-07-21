#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& a) {
    vector<int> ans;
    if (a.empty() || a[0].empty()) {
        return ans;
    }

    int n = a.size();
    int m = a[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; i++) {
            ans.push_back(a[top][i]);
        }
        top++;

        // Traverse rightmost column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(a[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }

        // Traverse leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    // input:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    vector<int> ans = spiralMatrix(matrix);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

return 0;
}