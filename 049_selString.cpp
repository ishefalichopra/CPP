#include<iostream>
using namespace std;
class solution{
    public:
    string javaSub(string s, int L, int R){
        string ans="";
        for(int i=L; i<=R; i++){
            ans = ans + s[i];
        }
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int L,R;
        cin>>L>>R;
        solution ob;
        cout<<ob.javaSub(s,L,R)<<endl;
    }

return 0;
}

