#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    for (const string &token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int a = s.top();
            s.pop(); // first popped (topmost)
            int b = s.top();
            s.pop(); // second popped

            if (token == "+")
                s.push(b + a);
            else if (token == "-")
                s.push(b - a); // correct order: b - a
            else if (token == "*")
                s.push(b * a);
            else if (token == "/")
                s.push(b / a); // correct order: b / a
        }
        else
        {
            s.push(stoi(token)); // convert token to integer and push onto the stack
        }
    }
    return s.top(); // final result
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};  
    cout << evalRPN(tokens) << endl; // Output: 9

    tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl; // Output: 6


    return 0;
}