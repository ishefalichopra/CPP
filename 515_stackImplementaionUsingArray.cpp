#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
vector<int>stack;
int s_size;
int n;

Stack(int n){
    this->stack.resize(n);
    this->s_size = -1;
    this->n = n;
}

void push(int x){
    if(s_size != n-1){
        s_size++;
        stack[s_size] = x;
    }
}

int pop(){
    if(s_size != -1){
        int x = stack[s_size];
        s_size--;
        return x;
    }
    return -1; // Stack is empty
}

int top(){
    if(s_size != -1){
        return stack[s_size];
    }
    return -1; // Stack is empty
}

int isEmpty(){
    return s_size == -1;
}

int isFull(){
    return s_size == n-1;
}

};


int main()
{
    int n;
    cin >> n; // Input the size of the stack
    Stack s(n); // Create a stack of size n

    int choice, value;
    while (true) {
        cout << "1. Push\n2. Pop\n3. Top\n4. Is Empty?\n5. Is Full?\n6. Exit\n";
        cin >> choice; // Input the choice

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value; // Input the value to push
                s.push(value);
                break;
            case 2:
                cout << "Popped value: " << s.pop() << endl; // Output the popped value
                break;
            case 3:
                cout << "Top value: " << s.top() << endl; // Output the top value
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl; // Check if stack is empty
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl; // Check if stack is full
                break;
            case 6:
                return 0; // Exit the program
            default:
                cout << "Invalid choice" << endl; // Invalid choice message
        }
    }

return 0;
}