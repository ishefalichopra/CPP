#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string delAlternate(string S){
        string s1;
        for(int i=0; i<S.length(); i++){
            if((i%2==0)||(i==0)){
                s1 = s1+S[i];
            }
        }
        return s1;
    }
};
int main()
{int t;
cin>>t;
while(t--){
    string S;
    cin>>S;
    Solution ob;
    auto ans= ob.delAlternate(S);
    cout<<ans<<endl;
}

return 0;
}