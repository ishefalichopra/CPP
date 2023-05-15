#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    string is_AutomorphicNumber(int n){
      int sqr = pow(n,2);
      while(n>0){
        if(n%10 != sqr%10)  return "Not Automorphic";
        n/=10;
        sqr/=10;
      }
      return "Automorphic";
    }
};
int main()
{
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.is_AutomorphicNumber(n)<<endl;

return 0;
}