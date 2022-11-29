#include<iostream>
using namespace std;
long long int sumseries(int n)
{
long long int x= n;
    return  (x*(x+1))/2;
}
int main()
{
int n;
cin>>n;
int ans =sumseries(n);
cout<<ans;
return 0;
}