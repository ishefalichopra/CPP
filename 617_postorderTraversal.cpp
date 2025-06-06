
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void reversePath(TreeNode *from, TreeNode *to)
{
    if (from == to)
        return;
    TreeNode *x = from;
    TreeNode *y = from->right;
    TreeNode *z;

    while (x != to)
    {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}

void collectReverse(TreeNode *from, TreeNode *to, vector<int> &res)
{
    reversePath(from, to);

    TreeNode *node = to;
    while (true)
    {
        res.push_back(node->val);
        if (node == from)
            break;
        node = node->right;
    }
    reversePath(to, from);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    TreeNode *dummy = new TreeNode(-1);
    dummy->left = root;
    TreeNode *curr = dummy;
    while (curr)
    {
        if (curr->left == nullptr)
        {
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = curr->left;

            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }

            if (!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                collectReverse(curr->left, pred, res);
                pred->right = nullptr;
                curr = curr->right;
            }
        }
    }
    delete dummy;
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}