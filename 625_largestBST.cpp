#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int solve(Node *root, int &maxSize, int &minVal, int &maxVal, bool &isBST)
{
    if (!root)
    {
        isBST = true;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        return 0;
    }

    int leftMax, leftMin, rightMax, rightMin;
    bool isLeftBST, isRightBST;

    int leftSize = solve(root->left, maxSize, leftMin, leftMax, isLeftBST);
    int rightSize = solve(root->right, maxSize, rightMin, rightMax, isRightBST);

    if (isLeftBST && isRightBST && root->data > leftMax && root->data < rightMin)
    {
        isBST = true;
        minVal = min(root->data, leftMin);
        maxVal = max(root->data, rightMax);
        int currSize = leftSize + rightSize + 1;
        maxSize = max(currSize, maxSize);
        return currSize;
    }

    isBST = false;
    maxSize = max(maxSize, max(leftSize, rightSize));
    return 0;
}

int largestBst(Node *root)
{

    bool isBST;
    int maxVal, minVal;
    int maxSize = 0;
    solve(root, maxSize, minVal, maxVal, isBST);
    return maxSize;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << "Size of the largest BST is: " << largestBst(root) << endl;

    return 0;
}