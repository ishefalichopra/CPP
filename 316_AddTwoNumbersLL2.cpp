#include<bits/stdc++.h>
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

ListNode* reverseList( ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* addtwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    int carry =0;

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    while(l1 != nullptr || l2 != nullptr || carry>0){
        int x = (l1!=nullptr) ? l1->val : 0;
        int y = (l2!=nullptr) ? l2->val : 0;
        int sum = x+y+carry;
        carry = sum/10;
        temp->next = new ListNode(sum%10);
        temp = temp->next;
    }
    return reverseList(dummy->next);
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addtwoNumbers(l1, l2);

    while(result != nullptr){
        cout<<result->val<<" ";
        result = result->next;
    }
return 0;
}