#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};


int check(Node* root){
    if(!root) return 0;

    if(!root->left && !root->right) return root->data;

    int leftSum = check(root->left);
    int rightSum = check(root->right);

    if(leftSum == -1 || rightSum == -1) return -1;

    if(root->data != leftSum + rightSum) return -1;

    return root->data + leftSum + rightSum;
}

bool isSumTree(Node* root){
    return check(root) != -1;
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

    cout<<isSumTree(root)<<endl;
    return 0;
}