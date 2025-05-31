#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int getMaxSumHelper(Node* node, unordered_map<Node*, int>& memo){
    if(!node) return 0;

    if(memo.find(node) != memo.end()){
        return memo[node];
    }

    int include = node->data;

    if(node->left) include += getMaxSumHelper(node->left->left, memo) + getMaxSumHelper(node->left->right, memo);
    if(node->right) include += getMaxSumHelper(node->right->left, memo) + getMaxSumHelper(node->right->right, memo);

    int exclude = 0;

    if(node->left) exclude += getMaxSumHelper(node->left, memo);
    if(node->right) exclude += getMaxSumHelper(node->right, memo);

    memo[node] = max(include, exclude);
    return memo[node];
}

int getMaxSum(Node* root){
    if(!root) return 0;
    unordered_map<Node*, int>memo;
    return getMaxSumHelper(root, memo);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << getMaxSum(root) << endl; 
    return 0;
}