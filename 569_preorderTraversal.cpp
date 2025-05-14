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


void preorderRecursive(Node* root){
    if(!root) return;
    cout<<root->data<<" ";

    if(root->left){
        preorderRecursive(root->left);
    }

    if(root->right){
        preorderRecursive(root->right);
    }
}

void preorderIterative(Node* root){
    if(!root) return;
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
       Node* curr = s.top();
       s.pop();
       cout<<curr->data<<" ";
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
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
    
    preorderRecursive(root);
    cout<<endl;
    preorderIterative(root);
    cout<<endl;
    

return 0;
}