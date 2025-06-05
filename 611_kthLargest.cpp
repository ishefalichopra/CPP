#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

int search(Node* root, int &k){
    if(!root) return -1;

    int val = search(root->right, k);
    if(val != -1) return val;

    k--;
    if(k == 0) return root->data;

    return search(root->left, k);
}

int kthLargest(Node* root, int k){
    return search(root, k);
}

int main()
{  
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k = 3; // Find the 3rd largest element
    int result = kthLargest(root, k);   
    if (result != -1) {
        cout << "The " << k << "rd largest element is: " << result << endl;
    } else {
        cout << "There are less than " << k << " elements in the tree." << endl;
    }

   
return 0;
}