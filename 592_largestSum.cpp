
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int solve(Node *root, int &maxSum)
{
    if (!root)
        return 0;
    int left = solve(root->left, maxSum);
    int right = solve(root->right, maxSum);
    int currentSum = root->data + left + right;
    maxSum = max(maxSum, currentSum);
    return currentSum;
}

int findLargestSubtreeSum(Node *root)
{
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << findLargestSubtreeSum(root) << endl; // Output: 7
    return 0;
}
