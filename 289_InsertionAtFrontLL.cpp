#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int data;
};

void insertAtFront(Node*& head, int newData){
    Node* newNode = new Node();
    newNode->data=newData;
    newNode->next=head;
    head=newNode;
}

void printList(Node* node){
    while(node!=nullptr){
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head = nullptr;

    insertAtFront(head, 5);
    insertAtFront(head, 4);
    insertAtFront(head, 3);

    printList(head);

return 0;
}