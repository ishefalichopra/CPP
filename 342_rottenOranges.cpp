#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    queue<pair<int, int>> q;
    int freshCnt = 0; // Count of fresh oranges
    int time = 0;     // To keep track of time

    // Step 1: Collect initial positions of rotten oranges and count fresh oranges
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 2)
            {
                q.push({i, j}); // Add rotten orange to the queue
            }
            else if (mat[i][j] == 1)
            {
                freshCnt++; // Count fresh oranges
            }
        }
    }

    // If there are no fresh oranges, return 0 (no time required to rot)
    if (freshCnt == 0)
        return 0;

    // Step 2: Define directions for up, down, left, and right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Step 3: BFS to spread the rotting process
    while (!q.empty())
    {
        int size = q.size(); // Number of rotten oranges at the current time step
        bool rotted = false;

        // Process all rotten oranges at the current level
        for (int i = 0; i < size; i++)
        {
            int x = q.front().first;
            int y = q.front().second; // Get the front element of the queue
            q.pop();

            // Check all four possible directions (up, down, left, right)
            for (auto &dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // If the adjacent cell is within bounds and has a fresh orange
                if (newX >= 0 && newX < row && newY >= 0 && newY < col && mat[newX][newY] == 1)
                {
                    // Rot the fresh orange and push it into the queue
                    mat[newX][newY] = 2;
                    q.push({newX, newY});
                    freshCnt--; // Decrease the fresh orange count
                    rotted = true;
                }
            }
        }

        // Only increment time if we rotted at least one fresh orange in this round
        if (rotted)
            time++;
    }

    // Step 4: If all fresh oranges are rotten, return the time, otherwise return -1
    return freshCnt == 0 ? time : -1;
}

int main()
{
    vector<vector<int>> mat = {{2, 1, 1},
                                {1, 1, 0},
                                {0, 1, 1}};
    cout << orangesRotting(mat) << endl;
    

    return 0;
}