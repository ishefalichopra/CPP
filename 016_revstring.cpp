#include<iostream>
using namespace std;
#include <iostream>
using namespace std;
// User function Template for C++

    string revStr(string S) {
        // code here
        string res="";
        for(int i=S.length();i>0;i--)
        {
            res=res+S[i-1];
        }
        return res;
    }
int main(){
    string S;
    cin>>S;
    cout<<revStr(S);
}