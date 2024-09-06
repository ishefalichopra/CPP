#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void rearrangeList(Node *&head)
{
    if (!head || !head->next)
        return;

    stack<Node *> nodeStack;
    Node *temp = head;

    // Push all nodes except the last one into the stack
    while (temp->next != NULL)
    {
        nodeStack.push(temp);
        temp = temp->next;
    }

    // Update head to point to the last node
    Node *lastNode = temp;
    head = lastNode;

    // Start popping the nodes and attach them at the end of the new list
    while (!nodeStack.empty())
    {
        Node *node = nodeStack.top();
        nodeStack.pop();
        lastNode->next = node;
        lastNode = node;
    }

    // Update the next pointer of the last node to NULL
    lastNode->next = NULL;
}
void push(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    cout << "Original Linked List: ";
    printList(head);
    rearrangeList(head);
    cout << "\nReversed Linked List: ";
    printList(head);

    return 0;
}