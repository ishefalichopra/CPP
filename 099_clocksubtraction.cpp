#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int clockSub(int num1, int num2){
        return (((num1-num2)+12)%12);
    }
};
int main()
{
    int num1, num2;
    cin>>num1>>num2;
    Solution obj;
    cout<<obj.clockSub(num1, num2);

return 0;
}