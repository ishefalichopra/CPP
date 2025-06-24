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

bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;

    ListNode *slow = head;
    ListNode *fast = getMiddle(head);

    fast = reverse(fast);

    while (fast != nullptr && slow != nullptr)
    {
        if (slow->val != fast->val)
            return false;

        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }


    return 0;
}