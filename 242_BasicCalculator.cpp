#include<bits/stdc++.h>
using namespace std;

int calculate(string s){
    s+= '+';
    stack<int> stk;
    long long int ans=0, curr=0;
    char sign='+';

    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            curr = curr*10 + s[i]-'0';
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            if(sign=='+'){
                stk.push(curr);
            }
            else if(sign=='-'){
                stk.push(-curr);
            }
            else if(sign=='*'){
                int temp = stk.top();
                stk.pop();
                stk.push(temp*curr);
            }
            else if(sign=='/'){
                int temp = stk.top();
                stk.pop();
                stk.push(temp/curr);
            }
            sign = s[i];
            curr = 0;
        }
    }
    while(stk.size()){
        ans+=stk.top();
        stk.pop();
    }
    return ans;
}

int main()
{
    string s = "3+2*2";
    cout<<calculate(s)<<endl;
return 0;
}