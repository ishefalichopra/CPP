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

void inorderConvert(Node *root, Node *&prev, Node *&head)
{
    if (!root)
        return;

    if (root->left)
        inorderConvert(root->left, prev, head);

    if (prev == nullptr)
    {
        head = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    if (root->right)
        inorderConvert(root->right, prev, head);
}

Node *bToDLL(Node *root)
{
    // code here
    Node *head = nullptr;
    Node *prev = nullptr;
    inorderConvert(root, prev, head);
    return head;
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

    Node *head = bToDLL(root);
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
    return 0;
}