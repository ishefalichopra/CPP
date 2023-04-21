#include<bits/stdc++.h>
using namespace std;
string to_upper(string str){
    //code
    for(int i=0; i<str.length();i++){
        str[i]= toupper(str[i]);
    }
    return str;
    
}
int main()
{
string str;
cin>>str;

cout<<to_upper(str);
return 0;
}