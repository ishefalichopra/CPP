#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *left, Node *right)
{
    if (!left)
        return right;

    if (!right)
        return left;

    Node *result = nullptr;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}
Node *mergeSort(Node *head)
{
    // your code here
    if (!head || !head->next)
        return head;

    Node *middle = findMiddle(head);
    Node *rightHalf = middle->next;
    middle->next = nullptr;

    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHalf);

    return merge(left, right);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(6);

    Node *sorted = mergeSort(head);
    while (sorted)
    {
        cout << sorted->data << " ";
        sorted = sorted->next;
    }

    return 0;
}