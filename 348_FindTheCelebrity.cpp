#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (mat[A][B] == 1)
        {
            s.push(B);
        }
        else
        {
            s.push(A);
        }
    }

    int potentialCelebrity = s.top();

    for (int i = 0; i < n; i++)
    {
        if (i != potentialCelebrity)
        {
            if (mat[potentialCelebrity][i] == 1)
            {
                return -1;
            }
            if (mat[i][potentialCelebrity] == 0)
            {
                return -1;
            }
        }
    }
    return potentialCelebrity;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0},
                                {0, 0, 0},
                                {0, 1, 0}};
    cout << celebrity(mat) << endl;
    

    return 0;
}