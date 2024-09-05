#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *next;
};

// Recursive function to search a key in the linked list
bool searchKey(Node *head, int x)
{
    // Base case: If head is NULL, the key is not found
    if (head == nullptr)
    {
        return false;
    }

    // If head's key matches x, return true
    if (head->key == x)
    {
        return true;
    }

    // Recursively search in the next node
    return searchKey(head->next, x);
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
    int key = 20;
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