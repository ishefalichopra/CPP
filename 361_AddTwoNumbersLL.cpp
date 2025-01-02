#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode(int val = 0, ListNode* next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};

ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;
    int carry = 0;

    while((l1!=nullptr)||(l2!=nullptr)||(carry!=0))
    {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + carry;

        carry = sum / 10;
        curr->next = new ListNode(sum % 10);

        curr = curr->next;
        if(l1 != nullptr) l1 = l1->next;
        if(l2 != nullptr) l2 = l2->next;    
    }
    return dummyHead->next;
}

int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* ans = AddTwoNumbers(l1, l2);
    while(ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;

return 0;
}