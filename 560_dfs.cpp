#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root){
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    if(root->left){
        preorder(root->left);
    }
    if(root->right){
        preorder(root->right);
    }
}

void inorder(Node* root){
    if(!root) return;

    if(root->left){
        inorder(root->left);
    }

    cout<<root->data<<" ";

    if(root->right){
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(!root) return;

    if(root->left){
        postorder(root->left);
    }

    if(root->right){
        postorder(root->right);
    }

    cout<<root->data<<" ";
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

return 0;
}