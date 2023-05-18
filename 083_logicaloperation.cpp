#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int logicaloperation(int A, int B, int C, int D, int E, int F){
        return (!A && B) || (C && D) || (E && !F);
    }
};
int main()
{
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    Solution s;
    cout<<s.logicaloperation(A,B,C,D,E,F)<<endl;

return 0;
}