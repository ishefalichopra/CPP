#include<bits/stdc++.h>
using namespace std;

class Queue{
struct Node{
    Node* next;
    int val;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
Node* front;
Node* rear;
public:

Queue(){
    front = NULL;
    rear = NULL;
}

void push(int x){
    Node* newNode = new Node(x);
    if(rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode; 
}

int pop(){
    if(front == NULL) return -1;
    int x = front->val;
    Node* temp = front;
    front = front->next;
    if(front == NULL) rear = NULL; // If the queue is empty after pop
    delete temp;
    return x;
}

int top(){
    if(front == NULL) return -1;
    return front->val;
}
};


int main()
{
    Queue q; // Create a queue

    int choice, value;
    while (true) {
        cout << "1. Push\n2. Pop\n3. Top\n4. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                q.push(value);
                break;
            case 2:
                cout << "Popped value: " << q.pop() << endl;
                break;
            case 3:
                cout << "Top value: " << q.top() << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

return 0;
}