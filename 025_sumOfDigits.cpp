#include<iostream>
using namespace std;
class Solution{
public:
    int sumOfDigits(int N){
        //code here
        int num=0;
        while(N!=0){
            int digit = N%10;
            num = num+digit;
            N=N/10;
        }
        return num;
    }
};
int main()
{
int t;
cin>>t;
while(t--){
    int N;
    cin>>N;
    Solution ob;
    cout<<ob.sumOfDigits(N)<<endl;
}
return 0;
}