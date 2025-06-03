#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int i = 0;
    void inorder(Node* root, vector<int>&in){
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    void createTree(Node* root, vector<int>& in) {
        if (!root) return;
        createTree(root->left, in);
        root->data = in[i++];
        createTree(root->right, in);
    }
  
    Node *binaryTreeToBST(Node *root) {
        vector<int> in;
        inorder(root, in);
        sort(in.begin(), in.end());
        int i = 0;
        createTree(root, in);
        return root;
    }


int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    root = binaryTreeToBST(root);

    cout << "Inorder traversal of the converted BST: ";
    vector<int> in;
    inorder(root, in);
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}