#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node *findLCA(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = findLCA(root->left, n1, n2);
    Node *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int calcDist(Node* root, int target, int dist = 0){
    if(!root) return -1;
    if(root->data == target) return dist;
    int left = calcDist(root->left, target, dist+1);
    if(left != -1) return left;
    return calcDist(root->right, target, dist+1);
}

int findDist(Node *root, int n1, int n2)
{
    Node *lca = findLCA(root, n1, n2);
    if (!lca)
        return -1;

    int d1 = calcDist(lca, n1);
    int d2 = calcDist(lca, n2);

    return d1 + d2;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1 = 4, n2 = 1;

    int distance = findDist(root, n1, n2);
    if (distance != -1)
        cout << "Distance between nodes " << n1 << " and " << n2 << " is: " << distance << endl;
    else
        cout << "One or both nodes not found in the tree." << endl;
    

    return 0;
}