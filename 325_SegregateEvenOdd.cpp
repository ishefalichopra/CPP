#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

Node *divide(Node *head)
{
    // code here
    Node *evenHead = new Node(0);
    Node *even = evenHead;
    Node *oddHead = new Node(0);
    Node *odd = oddHead;

    if (!head || !head->next)
        return head;

    while (head)
    {
        if (head->data % 2 == 0)
        {
            even->next = head;
            even = even->next;
        }
        else
        {
            odd->next = head;
            odd = odd->next;
        }
        head = head->next;
    }
    odd->next = nullptr;

    even->next = oddHead->next;

    Node *temp = evenHead->next;

    delete evenHead;
    delete oddHead;

    return temp;
}

int main()
{
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->next = new Node(1);

    printList(head);
    head = divide(head);
    printList(head);

    return 0;
}
