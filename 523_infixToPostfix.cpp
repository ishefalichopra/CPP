#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> s1;
    string res = "";

    for (char c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            res += c;
        }

        else if (c == '(')
        {
            s1.push('(');
        }
        else if (c == ')')
        {
            while (!s1.empty() && s1.top() != '(')
            {
                res += s1.top();
                s1.pop();
            }
            if (!s1.empty())
            {
                s1.pop(); // pop the '('
            }
        }
        else
        { // operator
            while (!s1.empty() && prec(s1.top()) >= prec(c))
            {
                res += s1.top();
                s1.pop();
            }
            s1.push(c);
        }
    }

    while (!s1.empty())
    {
        res += s1.top();
        s1.pop();
    }
    return res;
}

int main()
{

    string s = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(s) << endl; // Output: abcd^e-fgh*+^*i-
    
    return 0;
}