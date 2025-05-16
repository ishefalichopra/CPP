#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int toSumHelper(Node *node)
{
    if (!node)
        return 0;
    ;
    int leftSum = toSumHelper(node->left);
    int rightSum = toSumHelper(node->right);

    int oldVal = node->data;
    node->data = leftSum + rightSum;

    return node->data + oldVal;
}


void toSumTree(Node *node)
{
    toSumHelper(node);
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

    toSumTree(root);

    // Print the tree in-order
    stack<Node *> s;
    Node *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}