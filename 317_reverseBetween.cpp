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

ListNode* reverseBetween(ListNode* head, int left, int right){
    if(head == nullptr || left == right) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    for(int i=0; i<left-1; i++){
        prev = prev->next;
    }

    ListNode* curr = prev->next;
    ListNode* next = nullptr;

    for(int i=0; i<right-left; i++){
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
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

    int left = 2, right = 4;
    ListNode* result = reverseBetween(head, left, right);

    while(result != nullptr){
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;

return 0;
}