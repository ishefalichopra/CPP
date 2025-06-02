
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void findPreSuc(Node* root, Node* &pre, Node* &suc, int key){
    if(!root) return;

    // If key is found, find predecessor and successor
    if(root->data == key){
        // Find predecessor (max in left subtree)
        if(root->left){
            Node* temp = root->left;
            while(temp->right) temp = temp->right;
            pre = temp;
        }
        // Find successor (min in right subtree)
        if(root->right){
            Node* temp = root->right;
            while(temp->left) temp = temp->left;
            suc = temp;
        }
    } else if(key < root->data){
        suc = root; // Current node can be a successor
        findPreSuc(root->left, pre, suc, key);
    } else {
        pre = root; // Current node can be a predecessor
        findPreSuc(root->right, pre, suc, key);
    }
}

vector<Node*> findPreSuc(Node* root, int key){
    Node* pre = nullptr;
    Node* suc = nullptr;
    findPreSuc(root, pre, suc, key);
    return {pre, suc};
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);
    int target = 7;

    vector<Node*> result = findPreSuc(root, target);
    Node* pre = result[0];
    Node* suc = result[1];
    if(pre) {
        cout << "Predecessor of " << target << " is " << pre->data << endl;
    } else {
        cout << "No predecessor found for " << target << endl;
    }
    if(suc) {
        cout << "Successor of " << target << " is " << suc->data << endl;
    } else {
        cout << "No successor found for " << target << endl;
    }
    return 0;
}