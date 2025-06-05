
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, int &k, int &result) {
    if (!root) return;

    inorder(root->left, k, result);

    k--;
    if (k == 0) {
        result = root->data;
        return; // early exit
    }

    inorder(root->right, k, result);
}


int kthSmallest(Node *root, int k) {
    int result = -1;
    inorder(root, k, result);
    return result;
}


int main()
{  
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k = 3; // Find the 3rd smallest element
    int result = kthSmallest(root, k);
    if (result != -1) {
        cout << "The " << k << "rd smallest element is: " << result << endl;
    } else {
        cout << "There are less than " << k << " elements in the tree." << endl;
    }
   
return 0;
}