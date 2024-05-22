#include<bits/stdc++.h>
using namespace std;

char getMaxOccurence(string str){
    int max=-1;
    char c;
    int n=str.length();

    map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[str[i]]++;
    }
    for(auto it: mp){
        if(it.second>max){
            max=it.second;
            c= it.first;
        }
    }
    return c;
}


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<getMaxOccurence(s)<<endl;
    }
return 0;
}