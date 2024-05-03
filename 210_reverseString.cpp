#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str){
    string rev="";
    for(int i=str.size()-1;i>=0;i--){
        rev+=str[i];
    }
    return rev;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseWord(s) << endl;

return 0;
}