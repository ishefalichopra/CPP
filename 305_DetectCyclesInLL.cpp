#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

bool hasCycle(ListNode* head) {

        unordered_set<ListNode*> nodeSet;
        ListNode* temp = head;

        if (head == nullptr) {
            return false;
        }

        while (temp->next != nullptr) {

            if (nodeSet.find(temp) != nodeSet.end()) {
                return true;
            }
            nodeSet.insert(temp);
            temp = temp->next;
        }
        return false;
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

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = fifth;

    fifth->val = 5;
    fifth->next = nullptr;

    cout << "Original List: ";
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Has cycle: " << hasCycle(head) << endl;

return 0;
}