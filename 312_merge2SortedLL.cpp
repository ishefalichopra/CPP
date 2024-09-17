#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node *Merge2LL(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    Node *mergedList = dummy->next;
    delete dummy;
    return mergedList;
}

int main()
{
    // Create first sorted linked list: 1 -> 3 -> 5
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    // Create second sorted linked list: 2 -> 4 -> 6
    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    // Merge the two sorted linked lists
    Node *mergedList = Merge2LL(list1, list2);

    // Print the merged linked list
    Node *current = mergedList;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free the allocated memory
    while (mergedList != nullptr)
    {
        Node *temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}