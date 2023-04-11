#include<iostream>
using namespace std;
// User function Template for C++
class Solution {
  public:
    string conRevstr(string S1, string S2) {
        string S = S1 + S2;
        string new_str = " ";
            for (int i = S.length(); i >= 0; i--) {
                new_str += S[i];

    }
    return new_str;
    }
};

int main()
{int t;
cin>>t;
while(t--){
    string S1,S2;
    cin>>S1;
    cin>>S2;
    Solution ob;
    cout<<ob.conRevstr(S1,S2)<<endl;
}
return 0;
}