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

void postorderRecursive(Node *root)
{
    if (!root)
        return;

    if (root->left)
    {
        postorderRecursive(root->left);
    }

    if (root->right)
    {
        postorderRecursive(root->right);
    }
    cout << root->data << " ";
}

void postorderIterative(Node *root)
{
    if (!root)
        return;
    stack<Node *> s;
    s.push(root);
    stack<int> si;

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        si.push(curr->data);
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!si.empty())
    {
        cout << si.top() << " ";
        si.pop();
    }
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

    postorderRecursive(root);
    cout << endl;
    postorderIterative(root);
    cout << endl;

    return 0;
}