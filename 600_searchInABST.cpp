
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};


bool search(Node* root, int x){
    if(!root) return false;
    if(root->data == x) return true;
    if(x < root->data) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);
    int target = 7;

    if(search(root, target)){
        cout << "Element " << target << " found in the BST." << endl;
    } else {
        cout << "Element " << target << " not found in the BST." << endl;
    }

    return 0;
}