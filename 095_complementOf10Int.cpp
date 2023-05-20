#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int m = n;
int mask = 0;
while(m!=0){
    mask = (mask<<1)|1;
    m=m>>1;
}
int ans = (~n)&mask;
cout<<ans;
return 0;
}