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


void inorderRecursive(Node* root){
    if(!root) return;

    if(root->left){
        inorderRecursive(root->left);
    }

    cout<<root->data<<" ";

    if(root->right){
        inorderRecursive(root->right);
    }
}

void inorderIterative(Node* root){
    stack<Node*>s;

    Node* curr = root;

    while(!s.empty() || curr){
        if(curr){
            s.push(curr);
            curr = curr->left;
        }else{
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
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
    
    inorderRecursive(root);
    cout<<endl;
    inorderIterative(root);
    cout<<endl;
    

return 0;
}