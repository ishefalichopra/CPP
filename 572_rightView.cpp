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

vector<int> rightView(Node *root)
{
    vector<int> right;
    if (!root)
        return right;
    queue<Node *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        vector<int> level;
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q1.front();
            q1.pop();
            level.push_back(curr->data);
            if (curr->left)
                q1.push(curr->left);
            if (curr->right)
                q1.push(curr->right);
        }
        right.push_back(level[n - 1]);
    }
    return right;
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

    vector<int> right = rightView(root);

    cout << "Right view of the tree: ";
    for (int i = 0; i < right.size(); i++)
    {
        cout << right[i] << " ";
    }

    return 0;
}