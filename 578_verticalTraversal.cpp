
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> verticalOrder(Node *root)
{
    // Your code here
    vector<vector<int>> ans;
    if (!root)
        return ans;

    map<int, map<int, vector<int>>> mp;
    queue<pair<Node *, pair<int, int>>> q1;
    q1.push(make_pair(root, make_pair(0, 0)));

    while (!q1.empty())
    {

        pair<Node *, pair<int, int>> temp = q1.front();
        q1.pop();
        Node *curr = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        mp[hd][level].push_back(curr->data);

        if (curr->left)
            q1.push(make_pair(curr->left, make_pair(hd - 1, level + 1)));

        if (curr->right)
            q1.push(make_pair(curr->right, make_pair(hd + 1, level + 1)));
    }

    for (auto i : mp)
    {
        vector<int> col;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                col.push_back(k);
            }
        }
        ans.push_back(col);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = verticalOrder(root);

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