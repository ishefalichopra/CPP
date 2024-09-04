#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtEnd(Node *&head, int newdata)
{
    Node *newNode = new Node();
    newNode->data = newdata;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = nullptr; // Initialize an empty list

    // Insert nodes at the end of the list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    // Print the final list
    cout << "Final list: ";
    printList(head);

    return 0;
}