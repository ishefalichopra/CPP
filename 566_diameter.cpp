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

int maxDiameter = 0;
int height(Node *root)
{
    if (!root)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    maxDiameter = max(maxDiameter, leftH + rightH);
    return 1 + max(leftH, rightH);
}

int diameter(Node *root)
{
    maxDiameter = 0;
    height(root);
    return maxDiameter;
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

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Diameter of the tree: " << diameter(root) << endl;

    return 0;
}