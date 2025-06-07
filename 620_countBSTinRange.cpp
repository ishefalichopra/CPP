#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};


int getCount(Node* root, int l, int h){
    if(!root) return 0;
    int cnt = 0;
    if(root->data >= l && root->data <= h) {
        cnt = 1;
    }
    if(root->data > l) {
        cnt += getCount(root->left, l, h);
    }
    if(root->data < h) {
        cnt += getCount(root->right, l, h);
    }
    return cnt;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    int l = 2, h = 5;
    cout << "Count of nodes in range [" << l << ", " << h << "] is: " 
         << getCount(root, l, h) << endl;

    return 0;
}