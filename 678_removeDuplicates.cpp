#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            while (curr->next != nullptr && curr->val == curr->next->val)
                curr = curr->next;

            prev->next = curr->next;
        }
        else
        {
            prev = prev->next;
        }
        curr = curr->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(4);

    ListNode *result = deleteDuplicates(head);

    ListNode *current = result;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}