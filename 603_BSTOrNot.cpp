#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isBSTHelper(Node* root, int minVal, int maxVal){
    if(!root) return true;

    if(root->data <= minVal || root->data >= maxVal) return false;
    return isBSTHelper(root->left, minVal, root->data) && 
           isBSTHelper(root->right, root->data, maxVal);
}
bool isBST(Node* root) {
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    if(isBST(root)) {
        cout << "The tree is a Binary Search Tree." << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree." << endl;
    }
   
    return 0;
}