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

vector<int> diagonalTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q1;
    q1.push(root);

    while (!q1.empty())
    {
        Node *curr = q1.front();
        q1.pop();

        while (curr)
        {
            ans.push_back(curr->data);
            if (curr->left)
                q1.push(curr->left);
            curr = curr->right;
        }
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

    vector<int> ans = diagonalTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}