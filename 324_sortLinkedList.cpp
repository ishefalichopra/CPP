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

ListNode *findMiddle(ListNode *head)
{
    if (!head)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    // Move `slow` by 1 step and `fast` by 2 steps to find the middle.
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
ListNode *merge(ListNode *left, ListNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    ListNode *result = nullptr;

    // Pick either `left` or `right` based on their values
    if (left->val <= right->val)
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

// Function to perform merge sort on the linked list
ListNode *mergeSort(ListNode *head)
{
    if (!head || !head->next)
        return head;

    // Find the middle of the linked list
    ListNode *middle = findMiddle(head);
    ListNode *rightHalf = middle->next;
    middle->next = nullptr; // Split the list into two halves

    // Recursively sort the left and right halves
    ListNode *left = mergeSort(head);
    ListNode *right = mergeSort(rightHalf);

    // Merge the sorted halves
    return merge(left, right);
}

ListNode *sortList(ListNode *head) { return mergeSort(head); }

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode *result = sortList(head);
    

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}