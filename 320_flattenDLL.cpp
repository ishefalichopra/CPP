#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *prev;
    Node *next;
    Node *child;
    Node(int value)
    {
        val = value;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

Node *flatten(Node *head)
{
    if (!head)
        return head;

    stack<Node *> stack;
    Node *curr = head;

    while (curr)
    {
        if (curr->child)
        {
            if (curr->next)
            {
                stack.push(curr->next);
            }
            curr->next = curr->child;

            if (curr->next)
                curr->next->prev = curr;
            curr->child = nullptr;
        }

        if (!curr->next && !stack.empty())
        {
            Node *temp = stack.top();

            stack.pop();
            curr->next = temp;
            temp->prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->child = new Node(7);
    head->next->next->child->next = new Node(8);
    head->next->next->child->next->prev = head->next->next->child;
    head->next->next->child->next->next = new Node(9);
    head->next->next->child->next->next->prev = head->next->next->child->next;
    head->next->next->child->next->next->next = new Node(10);
    head->next->next->child->next->next->next->prev = head->next->next->child->next->next;

    Node *result = flatten(head);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    

    return 0;
}