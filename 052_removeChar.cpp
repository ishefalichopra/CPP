#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string removeCharacters(string S){
string s="";
for(int i=0;i<S.length();i++){
    if(isdigit(S[i])){
        s = s+ S[i];
    }
}
return s;
}
};
int main()
{
    string S;
    cin>>S;
    Solution ob ;
    cout<<ob.removeCharacters(S);

return 0;
}