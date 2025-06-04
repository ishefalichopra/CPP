#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int>& in){
    if(!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* buildBalancedTree(vector<int>& in, int start, int end){
    if(start > end) return nullptr;

    int mid = (start + end)/2;
    Node* root = new Node(in[mid]);

    root->left = buildBalancedTree(in, start, mid-1);
    root->right = buildBalancedTree(in, mid+1, end);

    return root;
}

Node* balancedBST(Node* root){
    vector<int>in;
    inorder(root, in);
    int start = 0, end = in.size()-1;
    return buildBalancedTree(in, start, end);
}

int main()
{  
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    root = balancedBST(root);

    cout << "Inorder traversal of the balanced BST: ";
    vector<int> in;
    inorder(root, in);
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;
return 0;
}