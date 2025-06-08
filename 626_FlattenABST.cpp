#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void solve(Node* root, Node*& prev, Node*& head) {
    if (!root) return;

    solve(root->left, prev, head);

    root->left = nullptr;
    if (prev)
        prev->right = root;
    else
        head = root;  // first node visited is the head

    prev = root;

    solve(root->right, prev, head);
}

Node* flattenBST(Node* root) {
    Node* prev = nullptr;
    Node* head = nullptr;
    solve(root, prev, head);
    return head;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* flattenedRoot = flattenBST(root);

    // Print the flattened tree
    Node* current = flattenedRoot;
    while (current) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;

    return 0;
}
