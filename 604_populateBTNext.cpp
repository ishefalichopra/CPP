#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *next; 
    Node(int x) : data(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void inorderTraversal(Node *root, vector<Node *> &ans)
{
    if (!root)
        return;
    inorderTraversal(root->left, ans);
    ans.push_back(root);
    inorderTraversal(root->right, ans);
}
void populateNext(Node *root)
{
    // code here
    vector<Node *> inorder;
    inorderTraversal(root, inorder);
    for (int i = 0; i < inorder.size() - 1; i++)
    {
        inorder[i]->next = inorder[i + 1];
    }
    inorder.back()->next = NULL;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    populateNext(root);
    Node *current = root;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    

    return 0;
}