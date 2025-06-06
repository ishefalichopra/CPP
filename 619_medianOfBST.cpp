#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
float findMedian(struct Node *root)
{
    vector<int> in;
    inorder(root, in);

    int n = in.size();

    if (n % 2 == 0)
    {
        return (in[n / 2] + in[n / 2 - 1]) / 2.0;
    }
    else
    {
        return in[n / 2];
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Median of BST: " << findMedian(root) << endl; // Output: 3
    return 0;
}
