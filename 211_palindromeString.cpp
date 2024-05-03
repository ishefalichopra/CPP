#include<bits/stdc++.h>
using namespace std;

string isPlaindrome(string S)
{
    string rev="";
    for(int i=S.size()-1;i>=0;i--){
        rev+=S[i];
    }
    if(rev==S)return "Yes";
    return "No";
}

int main()
{
    string s;
    cin >> s;
    cout << isPlaindrome(s) << endl;


return 0;
}