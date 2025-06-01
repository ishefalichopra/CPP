
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isIsomorphic(Node* r1, Node* r2){
    if(r1 && r2) return true;
    if(!r1 || !r2) return false;
    if(r1->data != r2->data) return false;

    bool noSwap = isIsomorphic(r1->left, r2->left) && isIsomorphic(r1->right, r2->right);
    bool swap = isIsomorphic(r1->left, r2->right) && isIsomorphic(r1->right, r2->left);

    return noSwap || swap;
}


int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
   
    
    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->left = new Node(7);
    root2->left->right = new Node(6);
    root2->right->left = new Node(5);
    root2->right->right = new Node(4);

    if(isIsomorphic(root1, root2)){
        cout << "The trees are isomorphic." << endl;
    } else {
        cout << "The trees are not isomorphic." << endl;
    }

    return 0;
}