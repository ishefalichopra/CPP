#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int n){
    int x = n;
    int rev = 0;

    while(n>0){
        int digit = n%10;
        rev = rev*10+digit;
        n = n/10;
    }

    return x==rev ? true : false;
}
int main()
{
    int n;
    cin>>n;
    cout<<checkPalindrome(n)<<endl;

return 0;
}