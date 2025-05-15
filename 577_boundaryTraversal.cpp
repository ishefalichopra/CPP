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

void traverseLeft(Node *root, vector<int> &ans)
{
    if (!root || !root->left && !root->right)
        return;

    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        ans.push_back(root->data);

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (!root || !root->left && !root->right)
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root)
{
    // code here
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->data);

    traverseLeft(root->left, ans); // left

    traverseLeaf(root->left, ans);  // leaf
    traverseLeaf(root->right, ans); // leaf

    traverseRight(root->right, ans); // right

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

    vector<int> ans = boundaryTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}