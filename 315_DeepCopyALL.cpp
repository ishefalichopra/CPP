#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int value)
    {
        val = value;
        next = nullptr;
        random = nullptr;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;

    // step 1: create new nodes inbetween original ones

    Node *curr = head;

    while (curr)
    {
        Node *newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // step 2: assign random pointers for the new nodes

    curr = head;

    while (curr)
    {
        if (curr->random)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // step 3: restore the original list and extract the copied one

    Node *copiedHead = head->next;
    Node *copyCurr = copiedHead;

    curr = head;

    while (curr)
    {
        curr->next = curr->next->next;
        if (copyCurr->next)
        {
            copyCurr->next = copyCurr->next->next;
        }
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    return copiedHead;
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);

    head->next->random = head;
    head->next->next->random = head->next;
    head->next->next->next->random = head->next->next;

    Node *copiedHead = copyRandomList(head);

    Node *curr = copiedHead;

    while (curr)
    {
        cout << curr->val << " ";
        if (curr->random)
        {
            cout << curr->random->val;
        }
        cout << endl;
        curr = curr->next;
    }

    

    return 0;
}