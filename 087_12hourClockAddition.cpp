#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int ClockSum(int num1, int num2){
        int sum = num1+num2;
        int m= sum%12;
        return m;
    }
};
int main()
{
    int num1, num2;
    cin>>num1>>num2;
    Solution obj;
    cout<<obj.ClockSum(num1, num2);

return 0;
}