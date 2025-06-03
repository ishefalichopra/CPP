#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* createTree(int pre[], int size, int minVal, int maxVal) {
    static int index = 0;

    if (index >= size) {
        return nullptr;
    }

    int value = pre[index];
    if (value < minVal || value > maxVal) {
        return nullptr;
    }

    Node* root = newNode(value);
    index++;

    root->left = createTree(pre, size, minVal, value);
    root->right = createTree(pre, size, value, maxVal);

    return root;
}

Node* Bst(int pre[], int size){
    return createTree(pre, size, INT_MIN, INT_MAX);
}

int main(){
    int pre[] = {10, 5, 3, 7, 15, 20};
    int n = sizeof(pre) / sizeof(pre[0]);

    Node* root = Bst(pre, n);
    cout << "Root of the BST is: " << root->data << endl;
    return 0;
}