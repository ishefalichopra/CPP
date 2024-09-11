#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void DeletionInStarting(Node*& head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = head;

    head = head->next;
    delete temp;
}

void DeletionInMiddle(Node*& head, int key){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* current=head;
    Node* prev=nullptr;

    while(current!=nullptr && current->data!=key){
        prev= current;
        current= current->next;
    }

    if(current==nullptr){
        cout<<"Key not found"<<endl;
        return;
    }

    prev->next= current->next;
    delete current;
}

void DeletionInEnd(Node*& head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while(current->next->next != nullptr){
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Utility function to insert a new node at the end
void append(Node*& head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

int main()
{
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Original List: ";
    printList(head);

    DeletionInStarting(head);
    cout << "After Deletion in Starting: ";
    printList(head);

    DeletionInMiddle(head, 3);
    cout << "After Deletion in Middle: ";
    printList(head);

    DeletionInEnd(head);
    cout << "After Deletion in End: ";
    printList(head);

return 0;
}