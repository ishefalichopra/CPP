#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* root){
    if(!root) return nullptr;
    while(root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNodeRecursive(Node* root, int key){
    if(root == nullptr) return nullptr;

    if(key < root->data)
    root->left = deleteNodeRecursive(root->left, key);
    else if(key > root->data)
    root->right = deleteNodeRecursive(root->right, key);
    else{
        //Ndoe found

        //case 1: Node with no child 

        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        //case 2: one child
        else if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //case 3: two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNodeRecursive(root->right, temp->data);
    }
    return root;
}

Node* deleteNodeIterative(Node* root, int key){
    if(!root) return nullptr;

    Node* parent = nullptr;
    Node* curr = root;

    while(curr && curr->data != key){
        parent = curr;
        if(key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(!curr) return root; // Node not found

    // Case 1: Node with no child
    if(!curr->left && !curr->right){
        if(parent){
            if(parent->left == curr)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        } else {
            delete root; // Deleting the root node
            return nullptr;
        }
        delete curr;
    }
    // Case 2: Node with one child
    else if(!curr->left || !curr->right){
        Node* child = (curr->left) ? curr->left : curr->right;
        if(parent){
            if(parent->left == curr)
                parent->left = child;
            else
                parent->right = child;
        } else {
            delete root; // Deleting the root node
            return child; // New root
        }
        delete curr;
    }
    // Case 3: Node with two children
    else{
        Node* temp = findMin(curr->right);
        int tempData = temp->data;
        root = deleteNodeIterative(root, tempData); // Delete the inorder successor
        curr->data = tempData; // Replace current node's data with inorder successor's data
    }

    return root;
}

void inorderTraversal(Node* root){
    if(!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main(){
    Node* root = nullptr;
    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    
    cout << "Inorder before deletion: ";
    inorderTraversal(root);
    cout << endl;

    int keyToDelete = 5;
    root = deleteNodeIterative(root, keyToDelete);

    cout << "Inorder after deleting " << keyToDelete << ": ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

