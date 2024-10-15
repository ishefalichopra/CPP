#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string S)
{
    // Your code here
    stack<int> st;

    for (char ch : S)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch (ch)
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string S = "231*+9-";
    cout << evaluatePostfix(S) << endl; // returns -4
    

    return 0;
}