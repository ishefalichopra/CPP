#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<int> s, mini;

public:
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (mini.empty() || x <= mini.top())
        {
            mini.push(x);
        }
    }

    void pop()
    {
        if (s.empty())
            return;
        int x = s.top();
        s.pop();
        if (x == mini.top())
        {
            mini.pop();
        }
    }

    int top()
    {
        if (s.empty())
            return -1;
        return s.top();
    }

    int getMin()
    {
        if (mini.empty())
            return -1;
        return mini.top();
    }
};

int main()
{
    MinStack minStack; // Create a MinStack
    int choice, value;

    while (true)
    {
        cout << "1. Push\n2. Pop\n3. Top\n4. Get Min\n5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            minStack.push(value);
            break;
        case 2:
            minStack.pop();
            cout << "Popped top element" << endl;
            break;
        case 3:
            cout << "Top element: " << minStack.top() << endl;
            break;
        case 4:
            cout << "Minimum element: " << minStack.getMin() << endl;
            break;
        case 5:
            return 0; // Exit the program
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}