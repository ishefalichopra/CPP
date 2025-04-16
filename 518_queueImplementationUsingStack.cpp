#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1, s2;
    public:

    Queue(){

    }

    void push(int x){
        s1.push(x);
    }
    
    int pop(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        if(s2.empty())return -1;
        int x = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    int top(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        if(s2.empty())return -1;
        int x = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }

    bool empty(){
        return s1.empty();
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