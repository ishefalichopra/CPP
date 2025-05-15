#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> zigZagTraversal(Node* root) {
       
        queue<Node*>q1;
        vector<int>ans;
         if(!root) return ans;
        bool flag = true;
        q1.push(root);
        while(!q1.empty()){
            int n = q1.size();
             deque<int> level; 
            for(int i=0;i<n;i++){
                Node* curr = q1.front();
                q1.pop();
                if(flag)
                level.push_back(curr->data);
                else
                level.push_front(curr->data);
                if(curr->left) q1.push(curr->left);
                if(curr->right) q1.push(curr->right);
            }
            ans.insert(ans.end(), level.begin(), level.end());
            flag = !flag;
        }
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

    vector<int>ans = zigZagTraversal(root);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}