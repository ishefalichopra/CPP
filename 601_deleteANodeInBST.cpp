
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* node){
    while(node && node->left){
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int k){
    if(!root) return nullptr;

    if(k < root->data){
        root->left = deleteNode(root->left, k);
    }else if(k > root->data){
        root->right = deleteNode(root->right, k);
    }else{
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
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
    int target = 7;

    if(deleteNode(root, target)){
        cout << "Element " << target << " deleted in the BST." << endl;
    } else {
        cout << "Element " << target << " not found in the BST." << endl;
    }

    return 0;
}