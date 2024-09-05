#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* reverseLL(Node* head){
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* curr = head;

    while(curr!=nullptr){
        next= curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


int main()
{
    Node* head = nullptr;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    cout<<"Original Linked List: ";
    printLL(head);

    head = reverseLL(head);

    cout<<"\nReversed Linked List: ";
    printLL(head);

return 0;
}