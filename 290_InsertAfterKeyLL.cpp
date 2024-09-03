#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void InsertAfterKey(Node *head, int key, int newData)
{
    Node *curr = head;
    // Traverse till the key is found
    while (curr != nullptr && curr->data != key)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "Node with key " << key << "not found." << endl;
        return;
    }

    Node *newNode = new Node();

    newNode->data = newData;

    newNode->next = curr->next;

    curr->next = newNode;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    cout << "original list ";
    printList(head);

    InsertAfterKey(head, 20, 25);

    cout << "after updating ";
    printList(head);

    return 0;
}