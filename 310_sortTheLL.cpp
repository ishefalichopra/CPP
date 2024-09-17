#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void sortList(Node *head)
{
    int cnt[3] = {0, 0, 0};
    Node *temp = head;

    while (temp != nullptr)
    {
        cnt[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;

    while (temp != nullptr)
    {
        if (cnt[i] == 0)
        {
            i++;
        }
        else
        {
            temp->data = i;
            cnt[i]--;
            temp = temp->next;
        }
    }
}



int main()
{
    Node *head = new Node(1);
    head->next = new Node(0);

    sortList(head);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}