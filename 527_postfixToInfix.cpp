#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postToInfix(string s) {
    // Write your code here.
    stack<string> s1;

    for(int i=0;i<s.length();i++){
        char c = s[i];

        if(isOperator(c)){
            string op2 = s1.top();
            s1.pop();

            string op1 = s1.top();
            s1.pop();

            string expr = "("+op1+c+op2+")";
            s1.push(expr);
        }else{
            s1.push(string(1,c));
        }
    }
    return s1.top();
}

int main()
{
    string s = "ab+cde+**";
    string ans = postToInfix(s);
    cout << "Infix : " << ans << endl;

return 0;
}