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

ListNode* removeNthFromEnd(ListNode* head, int n){
    if(head == nullptr) return nullptr;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    for(int i=0; i<n; i++){
        fast = fast->next;
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* result = removeNthFromEnd(head, n);

    while(result != nullptr){
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;

return 0;
}