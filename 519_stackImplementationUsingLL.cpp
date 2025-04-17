#include <bits/stdc++.h>
using namespace std;

class Stack
{
    struct Node
    {
        Node *next;
        int val;
        Node(int val)
        {
            this->val = val;
            next = NULL;
        }
    };

    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    int pop()
    {
        if (head == NULL)
            return -1;
        int x = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        return x;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        return head->val;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    Stack s; // Create a stack

    int choice, value;
    while (true)
    {
        cout << "1. Push\n2. Pop\n3. Top\n4. Is Empty\n5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            value = s.pop();
            if (value == -1)
                cout << "Stack is empty.\n";
            else
                cout << "Popped value: " << value << "\n";
            break;
        case 3:
            value = s.top();
            if (value == -1)
                cout << "Stack is empty.\n";
            else
                cout << "Top value: " << value << "\n";
            break;
        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;
        case 5:
            return 0; // Exit the program
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}