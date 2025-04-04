#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<char>> &board, int i, int j, string word, int index)
{
    if (index == word.size())
    {
        return true;
    }

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
    {
        return false;
    }

    if (board[i][j] != word[index])
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#'; // Mark as visited

    bool found = search(board, i + 1, j, word, index + 1) ||
                 search(board, i - 1, j, word, index + 1) ||
                 search(board, i, j + 1, word, index + 1) ||
                 search(board, i, j - 1, word, index + 1);

    board[i][j] = temp; // Unmark the visited cell
    return found;
}

bool exists(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (search(board, 0, 0, word, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    if (exists(board, word))
    {
        cout << "Word Found!" << endl;
    }
    else
    {
        cout << "Word Not Found!" << endl;
    }
    cout << endl;

    return 0;
}