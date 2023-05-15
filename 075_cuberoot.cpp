#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int cubeRoot(int N) {
        // code here
        int ans = cbrt(N);
        return ans;
    }
};
int main()
{int n;
cin>>n;
Solution ob;
cout<<ob.cubeRoot(n)<<endl;

return 0;
}