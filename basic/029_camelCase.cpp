#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int countCamelCase( string S){
        int count=0;
        for(int i=0; i<S.length(); i++){
          if(isupper(S[i])){
            count++;
          }
        }
        return count;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.countCamelCase(S)<<endl;
    }

return 0;
}