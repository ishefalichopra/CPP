#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfix(string &s)
{
    stack<string> s1;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        char c = s[i];

        if (isOperator(c))
        {
            string op1 = s1.top();
            s1.pop();
            string op2 = s1.top();
            s1.pop();

            string expr = op1 + "" + op2 + "" + c;
            s1.push(expr);
        }
        else
        {
            s1.push(string(1, c));
        }
    }
    return s1.top();
}


int main()
{
    string s = "*-A/BC-/AKL";
    cout << "Postfix : " << prefixToPostfix(s) << endl;

return 0;
}