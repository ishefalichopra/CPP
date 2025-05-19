#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int checkMirrorTree(int n, int e, int A[], int B[])
{
    // code here
    unordered_map<int, stack<int>> tree1;
    unordered_map<int, queue<int>> tree2;

    for (int i = 0; i < 2 * e; i += 2)
    {
        int u = A[i];
        int v = A[i + 1];
        tree1[u].push(v);
    }

    for (int i = 0; i < 2 * e; i += 2)
    {
        int u = B[i];
        int v = B[i + 1];
        tree2[u].push(v);
    }

    for (int i = 1; i <= n; i++)
    {
        stack<int> &s = tree1[i];
        queue<int> &q = tree2[i];

        while (!s.empty() && !q.empty())
        {
            if (s.top() != q.front())
            {
                return false;
            }
            s.pop();
            q.pop();
        }

        if (!s.empty() || !q.empty())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 7, e = 6;
    int A[] = {1, 2, 1, 3, 2, 4, 2, 5, 3, 6, 3, 7};
    int B[] = {1, 3, 1, 2, 3, 7, 3, 6, 2, 5, 2, 4};

    cout << checkMirrorTree(n, e, A, B) << endl;
    return 0;
}