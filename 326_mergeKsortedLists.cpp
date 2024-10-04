#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

struct compare{
    bool operator()(ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};

ListNode* mergeKSortedLists(vector<ListNode*> &lists){
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(auto l: lists){
        if(l)
            pq.push(l);
    }
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while(!pq.empty()){
        ListNode *top = pq.top();
        pq.pop();
        tail->next = top;
        tail = tail->next;
        if(top->next)
            pq.push(top->next);
    }
    return dummy->next;
}

int main()
{
    vector<ListNode*> lists;
    lists.push_back(new ListNode(1));
    lists.push_back(new ListNode(4));
    lists.push_back(new ListNode(5));
    lists.push_back(new ListNode(2));
    lists.push_back(new ListNode(3));
    lists.push_back(new ListNode(6));
    ListNode *head = mergeKSortedLists(lists);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }

return 0;
}