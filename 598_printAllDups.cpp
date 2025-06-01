
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

unordered_map<string, int> subtree;
vector<Node*> duplicates;

string serialize(Node* root){
    if(!root) return "#";

    string left = serialize(root->left);
    string right = serialize(root->right);

    string curr = to_string(root->data) + "," + left + "," + right;

    if(subtree[curr] == 1){
        duplicates.push_back(root);
    }
    subtree[curr]++;
    return curr;
}

vector<Node*> findDuplicates(Node* root) {
    subtree.clear();
    duplicates.clear();
    serialize(root);
    return duplicates;
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
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left->left = new Node(6); // Duplicate subtree
    root->right->left->right = new Node(7); // Duplicate subtree
    root->left->right->left = new Node(5); // Duplicate subtree
    root->left->right->right = new Node(4); // Duplicate subtree
    vector<Node*> dups = findDuplicates(root);
    for(Node* dup : dups) {
        cout << "Duplicate subtree rooted at node with value: " << dup->data << endl;
    }
    if(dups.empty()) {
        cout << "No duplicate subtrees found." << endl;
    }
    subtree.clear();
    duplicates.clear();

    return 0;
}