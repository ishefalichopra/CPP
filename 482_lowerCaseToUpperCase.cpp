#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    for(char c: s){
        if(c>='a' && c<='z'){
            cout<<char(c-32);
        }else{
            cout<<c;
        }
    }
return 0;
}