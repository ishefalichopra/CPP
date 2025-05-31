#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool findPath(Node *root, vector<Node *> &path, int k)
{
    if (!root)
        return false;

    path.push_back(root);

    if (root->data == k)
        return true;

    if (root->left && findPath(root->left, path, k) || root->right && findPath(root->right, path, k))
        return true;

    path.pop_back();
    return false;
}

Node *findLCA(Node *root, int n1, int n2)
{

    vector<Node *> path1, path2;

    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return nullptr;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i] != path2[i])
            break;
    }
    return path1[i - 1];
}

Node *findLCAOptimal(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = findLCAOptimal(root->left, n1, n2);
    Node *rightLCA = findLCAOptimal(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
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

    int n1 = 4, n2 = 5;
    // Node *lca = findLCA(root, n1, n2);
    Node* lca = findLCAOptimal(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}