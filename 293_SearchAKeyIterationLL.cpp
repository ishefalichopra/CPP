#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *next;
};

// Function to search a key in the linked list
bool searchKey(Node *head, int key)
{
    Node *curr = head; // Initialize current pointer to head
    while (curr != nullptr)
    {
        if (curr->key == key)
        { // If current node's key matches the key being searched
            return true;
        }
        curr = curr->next; // Move to the next node
    }
    return false; // Key not found
}

// Function to insert a node at the beginning of the list
void push(Node **head_ref, int new_key)
{
    Node *new_node = new Node();
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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

    // Searching for a key in the list
    int key = 30;
    if (searchKey(head, key))
    {
        cout << "Key " << key << " found in the linked list." << endl;
    }
    else
    {
        cout << "Key " << key << " not found in the linked list." << endl;
    }

    return 0;
}