#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy; // `prev` is a pointer to the node before the
                            // current sequence of duplicates

    while (head)
    {
        // Check if the current node is the start of a sequence of
        // duplicates
        if (head->next && head->val == head->next->val)
        {
            // Move `head` until the end of the duplicates
            while (head->next && head->val == head->next->val)
            {
                head = head->next;
            }
            // Skip all duplicates
            prev->next = head->next;
        }
        else
        {
            // No duplicates, just move `prev`
            prev = prev->next;
        }
        // Move to the next node
        head = head->next;
    }

    // The new head is after the dummy node
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    ListNode *result = deleteDuplicates(head);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}