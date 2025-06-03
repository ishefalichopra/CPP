#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};


Node *findLCAOptimal(Node *root, Node* n1, Node* n2)
{
    if (!root)
        return nullptr;

    if (root->data > n1->data && root->data > n2->data)
        return findLCAOptimal(root->left, n1, n2);
    if (root->data < n1->data && root->data < n2->data)
        return findLCAOptimal(root->right, n1, n2);
    return root; 
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);
    Node *n1 = root->left->left; // Node with value 3
    Node *n2 = root->left->right; // Node with value 7
    Node *lca = findLCAOptimal(root, n1, n2);
    if (lca)
    {
        cout << "LCA of " << n1->data << " and " << n2->data << " is: " << lca->data << endl;
    }
    else
    {
        cout << "LCA not found." << endl;
    }
    return 0;
}