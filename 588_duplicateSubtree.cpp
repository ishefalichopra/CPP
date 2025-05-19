#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool foundDuplicate = false;
unordered_map<string, int> subtreeMap;

string serialize(Node* root){
    if(!root) return "#";

    string left = serialize(root->left);
    string right = serialize(root->right);
    string curr = left + "," + right + "," + to_string(root->data);

    if(root->left || root->right){
        subtreeMap[curr]++;
        if(subtreeMap[curr] == 2){
            foundDuplicate = true;
        }
    }
    return curr;
}

int check(Node* root){
    subtreeMap.clear();
    foundDuplicate = false;
    serialize(root);
    return foundDuplicate;
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

    cout<<check(root)<<endl;
    return 0;
}