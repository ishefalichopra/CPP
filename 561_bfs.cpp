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

void bfs(Node* root){
    if(!root) return;
    queue<Node*>q1;
    q1.push(root);

    while(!q1.empty()){
        Node* curr = q1.front();
        q1.pop();

        cout<<curr->data<<" ";

        if(curr->left){
            q1.push(curr->left);
        }

        if(curr->right){
            q1.push(curr->right);
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

    bfs(root);
    cout<<endl;

return 0;
}