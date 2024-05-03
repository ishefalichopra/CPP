#include<bits/stdc++.h>
using namespace std;

bool cmp(char a, char b)
{
    if(a=='{'&&b=='}')return true;
    if(a=='('&&b==')')return true;
    if(a=='['&&b==']')return true;

    return false;
}

bool ispar(string x){
    stack<char>s;
    for(int i=0;i<x.size();i++){
     if(x[i]=='{'||x[i]=='('||x[i]=='['){
         s.push(x[i]);
     }
     else{
         if(s.empty())return false;
         if(cmp(s.top(),x[i])==false)return false;
         s.pop();
     }
    }
    if(s.empty())return true;
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << ispar(s) << endl;

return 0;
}