#include<bits/stdc++.h>
using namespace std;
string revStr(string S){
    int n=S.length();
    for(int i=0;i<n/2;i++){
        swap(S[i],S[n-i-1]);
    }
    return S;
}
int main()
{
    
    string S;
    cout<<"Enter the string:"<<endl;
    cin>>S;

    cout<<"Reversed string is:"<<revStr(S)<<endl;


return 0;
}