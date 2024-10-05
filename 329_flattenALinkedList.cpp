#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

Node *merge(Node *a, Node *b)
{
    // If either of the lists is empty, return the other one.
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result;

    // Choose the smaller value node
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = nullptr; // `next` should be set to null after merging
    return result;
}
Node *flatten(Node *root)
{
    // Your code here

    if (!root || !root->next)
        return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

int main()
{
    Node *root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);

    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);

    root->next->bottom = new Node(20);

    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    Node *head = flatten(root);
    while (head)
    {
        cout << head->data << " ";
        head = head->bottom;
    }

    return 0;
}