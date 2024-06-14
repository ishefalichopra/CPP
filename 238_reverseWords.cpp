#include<bits/stdc++.h>
using namespace std;

//reverse words in a string 

string reverseWrods(string s){
    s+=" ";
    string ans,t;

    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if(t!=""){
                ans = t+" "+ans;
            }
            else{
                t+=s[i];
            }
        }
    }
    return ans.substr(0,ans.size()-1);
}

int main()
{
    string s = "i like this program very much";
    string ans = reverseWrods(s);
    cout<<ans;

return 0;
}