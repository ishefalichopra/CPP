#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void treeToSortedDLL(Node *root, Node *&head)
{
    if (!root)
        return;
    treeToSortedDLL(root->right, head);
    root->right = head;
    if (head)
        head->left = root;
    head = root;
    treeToSortedDLL(root->left, head);
}

Node *mergeLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
            }
            tail = head1;
            head1 = head1->right;
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
            }
            tail = head2;
            head2 = head2->right;
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node *LLtoBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;

    Node *left = LLtoBST(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = LLtoBST(head, n - n / 2 - 1);

    return root;
}

void inorder(Node *root, vector<int> &in)
{
    if (!root)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> merge(Node *root1, Node *root2)
{
    Node *head1 = NULL;
    treeToSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    treeToSortedDLL(root2, head2);
    head2->left = NULL;

    Node *head = mergeLL(head1, head2);

    Node *newRoot = LLtoBST(head, countNodes(head));
    vector<int> in;
    inorder(newRoot, in);
    return in;
}

int main(){
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> merged = merge(root1, root2);
    
    for (int val : merged) {
        cout << val << " ";
    }
    
    return 0;
}