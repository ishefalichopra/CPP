#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

int getBinary(ListNode* head) {
    ListNode* temp = head;
    int result=0;

   while(temp!=nullptr){
    result = (result<<1) | temp->val;
    temp = temp->next;
   }
   return result;
}

int main()
{
    ListNode* head = nullptr;

    ListNode* second = nullptr;
    ListNode* third = nullptr;
    ListNode* fourth = nullptr;
    ListNode* fifth = nullptr;

    head = new ListNode();
    second = new ListNode();
    third = new ListNode();
    fourth = new ListNode();
    fifth = new ListNode();

    head->val = 1;
    head->next = second;

    second->val = 0;
    second->next = third;

    third->val = 1;
    third->next = fourth;

    fourth->val = 1;
    fourth->next = fifth;

    fifth->val = 0;
    fifth->next = nullptr;

    cout << "Original List: ";
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Binary: " << getBinary(head) << endl;

return 0;
}