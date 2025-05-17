#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int preIndex = 0;

Node *build(int start, int end, vector<int>& inorder, vector<int>& preorder, unordered_map<int,int>&mp){
    if(start>end){
        return nullptr;
    }
    
    int rootVal = preorder[preIndex++];
    Node *node = new Node(rootVal);
    int index = mp[rootVal];
    node->left = build(start, index-1, inorder, preorder, mp);
    node->right = build(index+1, end, inorder, preorder, mp);
    return node;
}

Node* buildTree(vector<int>& inorder, vector<int>& preorder){
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    return build(0, inorder.size()-1, inorder, preorder, mp);
}

int main()
{
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    Node *root = buildTree(inorder, preorder);
    return 0;
}