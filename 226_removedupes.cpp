#include<bits/stdc++.h>
using namespace std;

string removeDup(string s){
    map<char,int> mp;
    string temp;

    for (int i = 0; i < s.size(); i++)
    {
        if(mp[s[i]]==0){
            mp[s[i]]++;
            temp+=s[i];
        }
    }

    return temp;
    }

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<removeDup(s)<<endl;
    }

return 0;
}