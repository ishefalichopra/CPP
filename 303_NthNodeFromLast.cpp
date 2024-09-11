#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void NthNodeFromLast(Node* head, int n){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* first = head;
    Node* second = head;

    for(int i=0; i<n; i++){
        if(first == nullptr){
            cout<<"N is greater than the number of nodes in the list"<<endl;
            return;
        }
        first = first->next;
    }

    while(first != nullptr){
        first = first->next;
        second = second->next;
    }

    cout<<n<<"th node from the last is: "<<second->data<<endl;
}

int main()
{
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    Node* fourth = nullptr;
    Node* fifth = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = nullptr;

    cout << "Original List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    NthNodeFromLast(head, 2);

return 0;
}