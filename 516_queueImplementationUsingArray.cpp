#include<bits/stdc++.h>
using namespace std;

class Queue{


vector<int>queue;
int front;
int rear;

public:

Queue(){
    front = 0;
    rear = 0;
    queue.resize(100001); // Initial size of the queue
}

void enqueue(int x){
    queue[rear] = x;
    rear++;
}

int dequeue(){
    if(front == rear){
        return -1; // Queue is empty
    }
    int x = queue[front];
    front++;
    return x;
}


};

int main()
{

    Queue q; // Create a queue

    int choice, value;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Exit\n";
        cin >> choice; // Input the choice

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value; // Input the value to enqueue
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue(); // Dequeue an element
                if(value == -1){
                    cout << "Queue is empty" << endl;
                }else{
                    cout << "Dequeued: " << value << endl; // Output the dequeued value
                }
                break;
            case 3:
                return 0; // Exit the program
            default:
                cout << "Invalid choice" << endl; // Invalid choice message
        }
    }
return 0;
}