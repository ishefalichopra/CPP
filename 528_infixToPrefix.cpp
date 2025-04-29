#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

string toPostfix(string x)
{
    stack<char> s1;
    string res = "";

    for (int i = 0; i < x.length(); i++)
    {
        char c = x[i];

        if (isalnum(c))
        {
            res += c;
        }
        else if (c == '(')
        {
            s1.push(c);
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
                s1.pop();
            }
        }

        else
        {
            while (!s1.empty() && precedence(s1.top()) >= precedence(c))
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

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    string x = s;

    x = toPostfix(x);

    reverse(x.begin(), x.end());
    return x;
}

int main()
{
    string s = "(a+b)*(c+d)";
    string ans = infixToPrefix(s);
    cout << "Prefix : " << ans << endl;
    

    return 0;
}