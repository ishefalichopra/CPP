#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> cppOperators(int A, int B) {
        // code here
        vector<int> v;
            v.push_back(A+B);
            v.push_back(A*B);
            v.push_back((A>B) ? A-B : B-A);
            v.push_back((A>B) ? A/B : B/A);
        return v;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int A,B;
        cin>>A>>B;
        Solution ob;
        vector<int> v= ob.cppOperators(A,B);
        for(int c:v) cout<<c<<endl;
    }

return 0;
}