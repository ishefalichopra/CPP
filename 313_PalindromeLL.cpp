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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev; // prev will be the new head of the reversed list
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true; // A single node or empty list is a palindrome
    }

    // Step 1: Find the middle of the linked list using slow and fast
    // pointers
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2 reverse the second half
    ListNode *secondHalfStart = reverseList(slow);

    // Step 3: Compare the first half and the reversed second half
    ListNode *firstHalfStart = head;
    ListNode *secondHalf = secondHalfStart;

    while (secondHalf != nullptr)
    {
        if (firstHalfStart->val != secondHalf->val)
        {
            return false;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalf = secondHalf->next;
    }
    reverseList(secondHalfStart);
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << isPalindrome(head) << endl;

    return 0;
}