#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;  // To store elements being pushed
    stack<int> outputStack; // To store elements for popping or peeking
public:
    MyQueue() {
    }

    void push(int x) { inputStack.push(x); }

    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        // pop from outputStack
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }

    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    bool empty() { return inputStack.empty() && outputStack.empty(); }
};

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; // returns 1
    cout << q.pop() << endl;  // returns 1
    cout << q.empty() << endl; // returns false (not empty)

return 0;
}