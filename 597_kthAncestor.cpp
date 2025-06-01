#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void generateAncestors(Node* root, vector<int>& a){
    a[root->data] = -1;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr->left){
            a[curr->left->data] = curr->data;
            q.push(curr->left);
        }

        if(curr->right){
            a[curr->right->data] = curr->data;
            q.push(curr->right);
        }
    }
}

// int kthAncestor(Node* root, int k, int node){
//     vector<int>ancestors(100005, -1);

//     generateAncestors(root, ancestors);

//     while(node != -1 && k > 0){
//         node = ancestors[node];
//         k--;
//     }
//     return node;
// }

int ans = -1;

bool dfs(Node* root, int &k, int node){
    if(!root) return false;

    if(root->data == node) return true;

    if(dfs(root->left, k, node) || dfs(root->right, k, node)){
        k--;

        if(k == 0){
            ans = root->data;
        }
        return true;
    }
    return false;
}

int kthAncestor(Node* root, int k, int node){
    dfs(root, k, node);
    return ans;
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

    int k = 1, node = 6;

    int ans = kthAncestor(root, k, node);
    cout<<ans<<endl;

    return 0;
}