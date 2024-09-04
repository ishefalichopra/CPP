#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtPosition(Node *&head, int newdata, int position)
{
    Node *newNode = new Node();
    newNode->data = newdata;
    newNode->next = nullptr;

    // special case: Insert at the head(position = 1)
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (temp != nullptr && cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // If the position is beyond the list size
    if (temp == nullptr)
    {
        cout << "Position is beyond the list size" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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

    insertAtPosition(head, 25, 2);

    cout << "after updating ";
    printList(head);

    return 0;
}