#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
 string getBinaryRep(int N){
    cout<<bitset<30>(N);
 }
};
int main()
{ int t;
cin>>t;
while(t--){
    int N;
    cin>>N;
    Solution ob;
    cout<<ob.getBinaryRep(N)<<endl;
}

return 0;
}