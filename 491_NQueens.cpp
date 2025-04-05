#include <bits/stdc++.h>
using namespace std;

void checkQueens(int row, int n, vector<string > &board, vector<bool> &columns, vector<bool> &diag1,
                 vector<bool> &diag2, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        //check if the column or diagonals are occupied
        if (columns[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;
        //place the queen
        board[row][col] = 'Q';
        //mark the column and diagonals as occupied
        columns[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
        //recurse
        checkQueens(row + 1, n, board, columns, diag1, diag2, ans);
        //backtrack
        board[row][col] = '.';
        columns[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
    }
}

vector<vector<string>> nQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<bool> columns(n, false);
    vector<bool> diag1(2 * n - 2, false);
    vector<bool> diag2(2 * n - 2, false);
    checkQueens(0, n, board, columns, diag1, diag2, ans);
    return ans;
}

int main()
{ 
    int n;
    cin>>n;

    vector<vector<string>> ans = nQueens(n);

    for (const auto &board : ans)
    {
        for (const auto &row : board)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}