#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<Node*>q1;
        q1.push(root);
        while(!q1.empty()){
            int n = q1.size();
            vector<int>level;
            for(int i=0;i<n;i++){
            Node* curr = q1.front();
            q1.pop();
            level.push_back(curr->data);
            
            if(curr->left){
                q1.push(curr->left);
            }
            if(curr->right){
                q1.push(curr->right);
            }
          }
          ans.push_back(level);
        }
       return ans; 
    }

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

return 0;
}