#include<bits/stdc++.h>
using namespace std;

// Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

string duplicate(string s){
    map<char,int>mp;

    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    for(auto it: mp){
        if(it.second>1){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
 return "";
}

int main()
{
    string s;
    cin>>s;
    cout<<duplicate(s)<<endl;

return 0;
}