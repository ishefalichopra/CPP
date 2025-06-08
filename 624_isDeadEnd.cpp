#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr){}
};

void storeNodes(Node* root, unordered_set<int>& all, unordered_set<int>& leaves){
    if(!root) return;
    
    all.insert(root->data);
    
    if(!root->left && !root->right){
        leaves.insert(root->data);
    }
    
    storeNodes(root->left, all, leaves);
    storeNodes(root->right, all, leaves);
}

bool isDeadEnd(Node* root){
    unordered_set<int> all, leaves;
    all.insert(0);
    storeNodes(root, all, leaves);
    
    for(int leaf : leaves){
        if(all.count(leaf+1) && all.count(leaf-1)){
            return true;
        }
    }
    
    return false;
}

int main()
{
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    if(isDeadEnd(root)){
        cout << "The tree has a dead end." << endl;
    } else {
        cout << "The tree does not have a dead end." << endl;
    }


return 0;
}