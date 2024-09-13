#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

struct ListNode
{
    int val;
    ListNode *next;
};

long long ListToNumber(ListNode *head)
{
    long long result = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        result = (result * 10 + temp->val) % MOD;
        temp = temp->next;
    }
    return result;
}

long long Multiply(ListNode *head1, ListNode *head2)
{
    long long num1 = ListToNumber(head1);
    long long num2 = ListToNumber(head2);
    long long result = (num1 * num2) % MOD;
    return result;
}

int main()
{
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;

    ListNode *second1 = nullptr;
    ListNode *third1 = nullptr;
    ListNode *fourth1 = nullptr;
    ListNode *fifth1 = nullptr;

    head1 = new ListNode();
    second1 = new ListNode();
    third1 = new ListNode();
    fourth1 = new ListNode();
    fifth1 = new ListNode();

    head1->val = 1;

    head1->next = second1;

    second1->val = 0;
    second1->next = third1;

    third1->val = 1;
    third1->next = fourth1;

    fourth1->val = 1;
    fourth1->next = fifth1;

    fifth1->val = 0;
    fifth1->next = nullptr;

    ListNode *second2 = nullptr;

    head2 = new ListNode();
    second2 = new ListNode();
    head2->val = 1;
    head2->next = second2;
    second2->val = 0;
    second2->next = nullptr;

    cout << "Original List 1: ";
    ListNode *temp1 = head1;

    while (temp1 != nullptr)
    {
        cout << temp1->val << " -> ";
        temp1 = temp1->next;
    }
    cout << "NULL" << endl;

    cout << "Original List 2: ";
    ListNode *temp2 = head2;

    while (temp2 != nullptr)
    {
        cout << temp2->val << " -> ";
        temp2 = temp2->next;
    }

    cout << "NULL" << endl;

    cout << "Multiplication: " << Multiply(head1, head2) << endl;
    

    return 0;
}