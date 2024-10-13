#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            return -1;
        }
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    bool empty() { return q1.empty(); }
};

int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // returns 3
    cout << s.pop() << endl; // returns 3
    cout << s.top() << endl; // returns 2
    cout << s.empty() << endl; // returns 0

return 0;
}