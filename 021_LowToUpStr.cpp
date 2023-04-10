#include<bits/stdc++.h>
using namespace std;
string transform(string str);
string transform(string s){
    for(int i=0; i<s.length();i++){
        if(i==0 || s[i-1]==' '){
            s[i]=toupper(s[i]);
        }
       
    }
     return s;
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin,str);
        cout<<transform(str)<<endl;
    }
return 0;
}
