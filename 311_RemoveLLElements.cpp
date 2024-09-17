#include<bits/stdc++.h>
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

Node* removeLLElement(Node* head, int val){
    
    if(head!=nullptr && head->data == val){
        Node* dup = head;
        head = head->next;
        delete dup;
    }

    Node* temp = head;

    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->next->data == val){
            Node* dup = temp->next;
            temp->next = temp->next->next;
            delete dup;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);

    int val = 6;

    Node* newHead = removeLLElement(head, val);

    Node *temp = newHead;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

return 0;
}