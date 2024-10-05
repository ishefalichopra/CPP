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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prevGroupEnd = dummy;

    while (head)
    {
        // check if there are atleast k nodes in the list
        ListNode *end = head;
        for (int i = 1; i < k && end; i++)
        {
            end = end->next;
        }
        if (!end)
            break; // less than k nodes, so them be

        // Reverse k nodes
        ListNode *nextGroupStart = end->next;
        ListNode *curr = head;
        ListNode *prev = nullptr;

        // reverse the nodes in the current group
        for (int i = 0; i < k; i++)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // connect with the previous group
        prevGroupEnd->next = prev;
        head->next = nextGroupStart;

        // move the pointer to the next group
        prevGroupEnd = head;
        head = nextGroupStart;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);

    int k = 3;
    ListNode *newHead = reverseKGroup(head, k);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    
    return 0;
}