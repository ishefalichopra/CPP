#include<bits/stdc++.h>
using namespace std;

class Queue{
 queue<int> q1, q2;

 public:

 Queue(){

 }

 void push(int x){
    q2.push(x);
    while(!q1.empty()){
        q\q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
 }

 int pop(){
    if(q1.empty())return -1;
    int x = q1.front();
    q1.pop();
    return x;
 }

    int top(){
        if(q1.empty())return -1;
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main()
{

    Queue q; // Create a queue

    int choice, value;
    while (true) {
        cout << "1. Push\n2. Pop\n3. Top\n4. Exit\n";
        cin >> choice; // Input the choice

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value; // Input the value to push
                q.push(value);
                break;
            case 2:
                value = q.pop(); // Pop an element
                if(value == -1){
                    cout << "Queue is empty" << endl;
                }else{
                    cout << "Popped: " << value << endl; // Output the popped value
                }
                break;
            case 3:
                value = q.top(); // Get the top element
                if(value == -1){
                    cout << "Queue is empty" << endl;
                }else{
                    cout << "Top: " << value << endl; // Output the top value
                }
                break;
            case 4:
                return 0; // Exit the program
            default:
                cout << "Invalid choice" << endl; // Handle invalid choice
        }
    }
return 0;
}