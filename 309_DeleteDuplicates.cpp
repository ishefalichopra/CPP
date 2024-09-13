#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *deleteDuplicates(ListNode *head)
{

    if (!head)
        return nullptr; // Handle empty list

    ListNode *first = head;

    while (first != nullptr && first->next != nullptr)
    {
        // Compare the current node with the next node
        if (first->val == first->next->val)
        {
            // Duplicate found, delete the next node
            ListNode *duplicate = first->next;
            first->next = first->next->next; // Skip the duplicate node
            delete duplicate;                // Free memory of the duplicate node
        }
        else
        {
            first = first->next; // Move to the next node
        }
    }

    return head;
}

int main()
{
    ListNode *head = nullptr;

    ListNode *second = nullptr;

    ListNode *third = nullptr;

    ListNode *fourth = nullptr;

    ListNode *fifth = nullptr;

    head = new ListNode();

    second = new ListNode();

    third = new ListNode();

    fourth = new ListNode();

    fifth = new ListNode();

    head->val = 1;

    head->next = second;

    second->val = 1;

    second->next = third;

    third->val = 2;

    third->next = fourth;

    fourth->val = 3;

    fourth->next = fifth;

    fifth->val = 3;

    fifth->next = nullptr;

    cout << "Original List: ";

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    ListNode *newHead = deleteDuplicates(head);

    cout << "List after deleting duplicates: ";

    ListNode *temp1 = newHead;

    while (temp1 != nullptr)
    {
        cout << temp1->val << " -> ";
        temp1 = temp1->next;
    }

    cout << "NULL" << endl;

    return 0;
}