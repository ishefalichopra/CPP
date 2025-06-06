#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> in1;
    inorder(root1, in1);
    int cnt = 0;
    vector<int> in2;
    inorder(root2, in2);

    int i = 0, j = in2.size() - 1;

    while (i < in1.size() && j >= 0)
    {
        int sum = in1[i] + in2[j];
        if (sum == x)
        {
            cnt++;
            i++;
            j--;
        }
        else if (sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return cnt;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node *root2 = new Node(6);
    root2->left = new Node(7);
    root2->right = new Node(8);
    root2->left->left = new Node(9);
    root2->left->right = new Node(10);

    int x = 10;
    cout << countPairs(root1, root2, x) << endl;

    return 0;
}