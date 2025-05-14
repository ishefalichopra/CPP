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

vector<int> bottomView(Node *root)
{
    // Your Code Here
    vector<int> bottom;
    if (!root)
        return bottom;
    queue<pair<Node *, int>> q1;
    map<int, int> mp;
    q1.push({root, 0});

    while (!q1.empty())
    {
        auto it = q1.front();
        q1.pop();
        Node *curr = it.first;
        int line = it.second;
        mp[line] = curr->data;

        if (curr->left)
            q1.push({curr->left, line - 1});
        if (curr->right)
            q1.push({curr->right, line + 1});
    }
    for (auto &it : mp)
    {
        bottom.push_back(it.second);
    }
    return bottom;
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

    vector<int> bottom = bottomView(root);

    cout << "Bottom view of the tree: ";
    for (int i = 0; i < bottom.size(); i++)
    {
        cout << bottom[i] << " ";
    }

    return 0;
}