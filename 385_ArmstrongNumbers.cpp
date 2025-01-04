#include<bits/stdc++.h>
using namespace std;

bool armstrongNumber(int n){
    int ans = 0;
    int x = n;
    while(n>0){
        int digit = n%10;
        ans = ans + pow(digit,3);
        n = n/10;
    }
    return ans==x ? true : false;
}

int main()
{
    int n;
    cin>>n;
    cout<<armstrongNumber(n)<<endl;

return 0;
}