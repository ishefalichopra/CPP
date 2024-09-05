#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
    int key;
    Node *next;
};

// Recursive function to reverse the linked list
Node *reverseLinkedList(Node *head)
{
    // Base case: If the list is empty or only one node is left
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Recursively reverse the rest of the list
    Node *rest = reverseLinkedList(head->next);

    // Reverse the current node
    head->next->next = head;
    head->next = nullptr;

    // Return the new head of the reversed list
    return rest;
}

// Function to insert a node at the beginning of the list
void push(Node **head_ref, int new_key)
{
    Node *new_node = new Node();
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Start with an empty list
    Node *head = nullptr;

    // Adding some nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // Print the original list
    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list using recursion
    head = reverseLinkedList(head);

    // Print the reversed list
    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
