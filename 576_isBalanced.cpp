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

int height(Node *root)
{
    if (!root)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);

    return 1 + max(leftH, rightH);
}

bool isBalanced(Node *root)
{
    if (!root)
        return true;

    int leftH = height(root->left);
    int rightH = height(root->right);

    if (abs(leftH - rightH) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
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

    cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}