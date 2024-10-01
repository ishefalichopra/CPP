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

ListNode* partition(ListNode* head, int x){
    if(head == nullptr) return nullptr;

    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    ListNode* curr1 = dummy1;
    ListNode* curr2 = dummy2;

    while(head != nullptr){
        if(head->val < x){
            curr1->next = head;
            curr1 = curr1->next;
        }else{
            curr2->next = head;
            curr2 = curr2->next;
        }
        head = head->next;
    }

    curr2->next = nullptr;
    curr1->next = dummy2->next;
    return dummy1->next;
}

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    ListNode* result = partition(head, x);

    while(result != nullptr){
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;
return 0;
}