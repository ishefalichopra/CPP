#include<iostream>
using namespace std;

int convertfive(int n){
    int num=0;
    while(n!=0){
        int r= n%10;
        if(r==0){
            r=5;
        }
        num = num*10+r;
        n = n/10;
    }
    int ans =0;
    while(num!=0){
        int r=num%10;
        ans = ans*10+r;
        num=num/10;
    }
    return ans;
}
int main()
{
int n;
cin>>n;
cout<<convertfive(n);
return 0;
}