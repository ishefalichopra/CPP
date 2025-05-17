#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool check(Node* root){
    if(!root) return 0;

    queue<pair<Node*, int>>q1;
    q1.push({root, 0});
    int leafLevel = -1;
    while(!q1.empty()){
        auto it = q1.front();
        q1.pop();
        Node* node = it.first;
        int level = it.second;

        if(!node->left && !node->right){
            if(leafLevel == -1){
                leafLevel = level;
            }
            else if(leafLevel != level){
                return false;
            }
        }

        if(node->left) q1.push({node->left, level + 1});
        if(node->right) q1.push({node->right, level + 1});
    }
    return true;
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

    cout<<check(root)<<endl;
    return 0;
}