#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    int a=0;
    int b=1;
    int c;
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<n;i++){
        c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    return 0;

}
int main()
{
int n;
cin>>n;
cout<<fib(n)<<endl;
return 0;
}