#include<bits/stdc++.h>
using namespace std;
sturct Node
{
    int data;
    Node* next;
};

void removeLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = sow->next;
        fats = fast->next->next;
        if(slow == fast) break;
    }
    
    if(slow != fast) return;

    slow = head;

    if(slow == fast){
        while(fast->next != slow){
            fast = fast->next;
        }
    }else{
        while(fast->next != slow->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = nullptr;
}


int main()
{
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 4;
    head->next->next->next->next = head; // Creating a loop

    removeLoop(head);

    // Print the list to verify the loop is removed
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

return 0;
}