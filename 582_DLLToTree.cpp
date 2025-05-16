#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;  
    Node* right; 
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(Node* head){
    int count = 0;
     while (head) {
        count++;
        head = head->right;
    }
    return count;
}

Node* DLLtoTreeHelper(Node*& head, int n){
   if(n <= 0 || !head) return nullptr;

    Node* left = DLLtoTreeHelper(head, n/2);
    Node* root = head;
    root->left = left;
    head = head->right;
    root->right = DLLtoTreeHelper(head, n - n/2 - 1);
    return root;
}

Node* DLLtoTree(Node* head) {
    if(!head) return nullptr;
    int n = countNodes(head);
    return DLLtoTreeHelper(head, n);
}

int main()
{
    // Create a doubly linked list
    Node* head = new Node(1);
    head->right = new Node(2);
    head->right->left = head;
    head->right->right = new Node(3);
    head->right->right->left = head->right;

    // Convert the doubly linked list to a binary tree
    Node* root = DLLtoTree(head);

    // Print the binary tree in-order
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }

return 0;
}