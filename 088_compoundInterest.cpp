#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int compoundInterest(int P, int R, int T, int N){
        int CI = P * pow((1 +0.01* R/N), T*N);
        return CI;
    }
};
int main()
{
    int P, R, T, N;
    cin>>P>>R>>T>>N;
    Solution obj;
    cout<<obj.compoundInterest(P, R, T, N);

return 0;
}