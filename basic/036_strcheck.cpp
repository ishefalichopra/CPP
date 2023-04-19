#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        bool check (string s)
        {
        	//code here.
        	for(int i=1; i<s.length();i++){
        	    if(s[0]!=s[i]){
        	       return false;
        	    }
        	    
        	}
        	return true;
        }
};

int main()
{
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    Solution ob;
    if(ob.check(s)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    
}
return 0;
}