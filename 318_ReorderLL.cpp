#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value)
    {
        val = value;
        next = nullptr;
    }
};

void reorderList(ListNode *head)
{
    if (!head || !head->next)
        return;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *prev = nullptr;
    ListNode *curr = slow->next;
    slow->next = nullptr; // Split the list into two halves
    while (curr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Merge the two halves
    ListNode *first = head;
    ListNode *second =
        prev; // `prev` is the head of the reversed second half
    while (second)
    {
        ListNode *temp1 = first->next;
        ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    reorderList(head);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    

    return 0;
}