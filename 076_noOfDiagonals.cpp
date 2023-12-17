#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    long long diagonals(int n){
        return 1ll*n*(n-3)/2;
    }
};
int main()
{
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.diagonals(n)<<endl;

return 0;
}