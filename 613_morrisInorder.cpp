
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void morris_inorder(Node* root){
    Node* curr = root;
    while(curr){
        if(!curr->left){
            cout<<curr->data<<" ";
            curr = curr->right;
        }else{
            Node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
            if(!pred->right){
                pred->right = curr;
                curr = curr->left;
            }else{
                pred->right = nullptr;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
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
    morris_inorder(root);
   
return 0;
}