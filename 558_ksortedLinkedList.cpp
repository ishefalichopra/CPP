#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node *sortKSortedDLL(Node *head, int k)
{
    if (!head)
        return head;
    Node *curr = head->next;
    while (curr)
    {
        Node *next = curr->next;
        Node *temp = curr->prev;
        int cnt = 0;

        while (temp && cnt < k && temp->data > curr->data)
        {
            temp = temp->prev;
            cnt++;
        }

        if (curr->prev)
        {
            curr->prev->next = curr->next; // remove curr
        }
        if (curr->next)
        {
            curr->next->prev = curr->prev;
        }
        // Insert after temp
        if (!temp)
        {
            // insert at beginning
            curr->next = head;
            head->prev = curr;
            curr->prev = nullptr;
            head = curr;
        }
        else
        {
            curr->next = temp->next;
            if (temp->next)
            {
                temp->next->prev = curr;
            }
            temp->next = curr;
            curr->prev = temp;
        }
        curr = next;
    }
    return head;
}
struct compare
{
    operator()(Node * a, Node * b)
    {
        return a->data > b->data;
    }
};

Node *sortKSortedDLLUsingHeap(Node *head, int k)
{
    if (!head)
        return head;
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *newHead = nullptr;
    Node *last = nullptr;

    for (int i = 0; head && i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {
        Node *smallest = pq.top();
        pq.pop();

        if (!newHead)
        {
            newHead = smallest;
            newHead->prev = nullptr;
            last = newHead;
        }
        else
        {
            last->next = smallest;
            smallest->prev = last;
            last = smallest;
        }

        if (head)
        {
            pq.push(head);
            head = head->next;
        }
    }
    last->next = nullptr;
    return newHead;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(10);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next->next->next->prev = head->next->next->next->next->next->next;
    head->next->next->next->next->next->next->next->next->next = new Node(13);

    // sortKSortedDLL(head, 3);

    sortKSortedDLLUsingHeap(head, 3);
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}