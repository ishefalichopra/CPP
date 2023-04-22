#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
long long int sum_of_square_evenNumbers(long long int n){
    return (2*n*(n+1)*(2*n+1))/3;
}
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        Solution ob;
        long long int ans = ob.sum_of_square_evenNumbers(n);
    }

return 0;
}