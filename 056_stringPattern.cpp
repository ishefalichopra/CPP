#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
vector<string> pattern(string s){
    vector<string>ans;
    int len = s.length();
    string temp=" ";
    while(len>0){
        for(int i=0;i<len;i++){
            temp =temp+ s[i];
            ans.push_back(temp);
            len--;
            temp = " ";
        }
        
    }
    return ans;
}
};
int main()
{
    string s;
    getline(cin,s);
    Solution ob;
    vector<string> ans=ob.pattern(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
return 0;
}