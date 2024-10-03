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

ListNode *ZigZag(ListNode *head)
{
    if (!head || !head->next)
        return head;

    bool flag = true;

    ListNode *curr = head;
    while (curr->next)
    {
        if (flag)
        {
            if (curr->val < curr->next->val)
            {
                swap(curr->val, curr->next->val);
            }
        }else{
            if(curr->val > curr->next->val){
                swap(curr->val, curr->next->val);
            }
        }
        flag = !flag;
        curr = curr->next;
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    ListNode *result = ZigZag(head);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    
    return 0;
}
