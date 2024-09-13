#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    unordered_set<ListNode *> nodeSet;
    while (headA != nullptr)
    {
        nodeSet.insert(headA);
        headA = headA->next;
    }

    while (headB != nullptr)
    {
        if (nodeSet.find(headB) != nodeSet.end())
        {
            return headB;
        }
        headB = headB->next;
    }

    return nullptr;
}

int main()
{
    ListNode *headA = nullptr;
    ListNode *headB = nullptr;

    ListNode *secondA = nullptr;
    ListNode *thirdA = nullptr;
    ListNode *fourthA = nullptr;
    ListNode *fifthA = nullptr;

    headA = new ListNode();
    secondA = new ListNode();
    thirdA = new ListNode();
    fourthA = new ListNode();
    fifthA = new ListNode();

    headA->val = 4;

    headA->next = secondA;

    secondA->val = 1;
    secondA->next = thirdA;

    thirdA->val = 8;
    thirdA->next = fourthA;

    fourthA->val = 4;
    fourthA->next = fifthA;

    fifthA->val = 5;
    fifthA->next = nullptr;

    ListNode *secondB = nullptr;
    ListNode *thirdB = nullptr;
    
    headB = new ListNode();
    secondB = new ListNode();

    headB->val = 5;
    headB->next = secondB;

    secondB->val = 0;
    secondB->next = thirdB;

    thirdB = new ListNode();
    thirdB->val = 1;
    thirdB->next = fourthA;

    cout << "Original List 1: ";

    ListNode *temp1 = headA;

    while (temp1 != nullptr)
    {
        cout << temp1->val << " -> ";
        temp1 = temp1->next;
    }

    cout << "NULL" << endl;

    cout << "Original List 2: ";

    ListNode *temp2 = headB;

    while (temp2 != nullptr)
    {
        cout << temp2->val << " -> ";
        temp2 = temp2->next;
    }

    cout << "NULL" << endl;

    ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr)
    {
        cout << "Intersection Node: " << intersection->val << endl;
    }
    else
    {
        cout << "No Intersection Node" << endl;
    }
    


    return 0;
}