
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insertRecursive(Node* root, int key){
    if(!root) return new Node( key);

    if(key < root->data)
    root->left = insertRecursive(root->left, key);

    else if(key > root->data)
    root->right = insertRecursive(root->right, key);

    return root;
}

Node* insertIterative(Node* root, int key){
    Node* newNode = new Node(key);
    if(!root) return newNode;

    Node* parent = nullptr;
    Node* curr = root;

    while(curr != nullptr){
        parent = curr;

        if(key < curr->data)
        curr = curr->left;
        else if(key > curr->data)
        curr = curr->right;
        else return root; //No dupliactes
    }

    if(key > parent->data)
    parent->right = newNode;
    else 
    parent->left = newNode;
    return root;
}

int main(){
    Node* root = nullptr;
    root = insertIterative(root, 10);
    root = insertIterative(root, 5);
    root = insertIterative(root, 15);
    root = insertIterative(root, 3);
    root = insertIterative(root, 7);

    // In-order traversal to print the BST
    stack<Node*> s;
    Node* curr = root;

    while(curr != nullptr || !s.empty()){
        while(curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}