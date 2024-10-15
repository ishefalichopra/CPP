#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{

    twoStacks *sq = new twoStacks(5);

    sq->push1(5);
    sq->push2(10);
    sq->push2(15);
    sq->push1(11);
    sq->push2(7);

    cout << "Popped element from stack1 is " << sq->pop1() << endl;
    sq->push2(40);
    cout << "Popped element from stack2 is " << sq->pop2() << endl;
                                        

    return 0;
}