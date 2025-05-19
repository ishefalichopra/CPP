#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
void solve(Node *root, int len, int sum, int &maxlen, int &maxSum)
{
    if (!root)
        return;

    sum += root->data;
    len++;

    if (!root->left && !root->right)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }
        else if (len == maxlen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    solve(root->left, len, sum, maxlen, maxSum);
    solve(root->right, len, sum, maxlen, maxSum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int maxlen = 0;
    int maxSum = 0;
    solve(root, 0, 0, maxlen, maxSum);
    return maxSum;
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
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    cout << sumOfLongRootToLeafPath(root)<< endl;
    return 0;
}