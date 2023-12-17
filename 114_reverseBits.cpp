#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long reverseBits(long long X){
        long long ans =0;
        int exp =31;
        int rem;
        while(X){
            rem = X%2;
            ans += rem*pow(2,exp);
            exp--;
            X/=2;
        }
        return ans;
    }
};
int main()
{
    long long X;
    cin >> X;
    Solution obj;
    cout << obj.reverseBits(X) << endl;

return 0;
}