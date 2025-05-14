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
vector<int> leftView(Node *root)
{
    // code here
    vector<int> left;
    if (!root)
        return left;
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
        left.push_back(level[0]);
    }
    return left;
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

    vector<int> left = leftView(root);
   
    cout << "Left view of the tree: ";
    for (int i = 0; i < left.size(); i++)
    {
        cout << left[i] << " ";
    }

    return 0;
}