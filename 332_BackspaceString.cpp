#include <bits/stdc++.h>
using namespace std;

void push(stack<char> &s, char x) { s.push(x); }
void pop(stack<char> &s)
{
    if (!s.empty())
    {
        s.pop();
    }
}
bool backspaceCompare(string s, string t)
{

    stack<char> s1;
    stack<char> s2;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '#')
        {
            push(s1, s[i]);
        }
        else
        {
            pop(s1);
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] != '#')
        {
            push(s2, t[i]);
        }
        else
        {
            pop(s2);
        }
    }
    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() != s2.top())
        {
            return false;
        }
        s1.pop();
        s2.pop();
    }
    return s1.empty() && s2.empty();
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    cout << backspaceCompare(s, t) << endl; // returns true

    return 0;
}