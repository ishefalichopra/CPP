#include<bits/stdc++.h>
using namespace std;

int priority(char c){
        if(c == '^')return 3;
        else if((c == '*')|| (c == '/')) return 2;
        else if((c == '+') || (c == '-')) return 1;
        return 0;
    }

    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string ans = "";
        
        for(char c: s){
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9')) 
            ans += c;
            
            else if (c == '(')
            st.push('(');
            else if (c == ')') {
            while (st.top() != '(') {
                ans += st.top();
                st.pop();
            }
               st.pop(); 
            } else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
        while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
       return ans; 
    }

int main()
{
    string s;
    cin >> s;

    string result = infixToPostfix(s);
    cout << result << endl;

return 0;
}