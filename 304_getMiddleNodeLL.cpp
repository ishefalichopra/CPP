#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;

    if (head == nullptr)
    {
        return head;
    }
    while (temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }

    temp = head;

    int mid = cnt / 2;

    while (mid)
    {
        temp = temp->next;
        mid--;
    }
    return temp;
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

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = fifth;

    fifth->val = 5;
    fifth->next = nullptr;

    cout << "Original List: ";
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    ListNode *mid = middleNode(head);
    cout << "Middle Node: " << mid->val << endl;

    return 0;
}