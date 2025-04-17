#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<int> s1;
    for (char c : s)
    {
        if (c == '()' || c == '[' || c == '{')
        {
            s1.push(c);
        }
        else
        {
            if (s1.empty())
                return false;

            char top = s1.top();
            s1.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return s1.empty();
}

int main()
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}