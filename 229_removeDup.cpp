#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string str) {
	    // code here
	    map<char,int>mp;
	    string temp;
	    
	    for(int i=0;i<str.size();i++){
	        if(mp[str[i]]==0){
	        mp[str[i]]++;
	        temp+=str[i];
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
        cout<<removeDuplicates(s)<<endl;
    }


return 0;
}