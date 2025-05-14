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

vector<int> topView(Node *root) {
      vector<int> top;
       if (!root)
        return top;
       queue<pair<Node *,int>> q1;
       map<int, int>mp;
       q1.push({root,0});
       while (!q1.empty())
       {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            auto it = q1.front();
            int line = it.second;
            Node *curr = it.first;
            q1.pop();
            
            if(mp.find(line) == mp.end()){
                mp[line] = curr->data;
            }
            
            if(curr->left) q1.push({curr->left, line-1});
            if(curr->right) q1.push({curr->right, line+1});
        }
       }
         for(auto &it: mp){
           top.push_back(it.second);
         }
        
        return top;
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

    vector<int> top = topView(root);

    cout << "Top view of the tree: ";
    for (int i = 0; i < top.size(); i++)
    {
        cout << top[i] << " ";
    }

    return 0;
}