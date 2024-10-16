#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct Cell
    {
        int row;
        int col;
    };

public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<Cell> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    distances[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            Cell current = q.front();
            q.pop();

            for (auto &dir : directions)
            {
                int newRow = current.row + dir.first;
                int newCol = current.col + dir.second;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && distances[newRow][newCol] == INT_MAX)
                {
                    distances[newRow][newCol] = distances[current.row][current.col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return distances;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, 0, 0, 1},
                                 {0, 0, 0, 1, 0},
                                 {0, 0, 0, 0, 0}};
    Solution obj;
    vector<vector<int>> result = obj.nearest(grid);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    

    return 0;
}