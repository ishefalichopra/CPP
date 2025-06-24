#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void reorder(ListNode *head)
{
    if (!head || !head->next)
        return;

    ListNode *mid = getMiddle(head);
    ListNode* fast = reverse(mid->next);
    mid->next = nullptr;

    ListNode *slow = head;
    while (fast != nullptr && slow != nullptr)
    {
        ListNode* temp = slow->next;
        ListNode* temp1 = fast->next;
        slow->next = fast;
        fast->next = temp;
        slow = temp;
        fast = temp1;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    reorder(head);

    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}