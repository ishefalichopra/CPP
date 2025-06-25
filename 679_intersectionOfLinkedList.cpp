#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return nullptr;
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1 != temp2)
    {
        temp1 = temp1 ? temp1->next : headB;
        temp2 = temp2 ? temp2->next : headA;
    }
    return temp1;
}

int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode *headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = headA->next->next; // Intersection at node with value 3

    ListNode *intersectionNode = getIntersectionNode(headA, headB);
    if (intersectionNode)
    {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    }
    else
    {
        cout << "No intersection found." << endl;
    }
    return 0;
}