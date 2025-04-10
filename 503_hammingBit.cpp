#include<bits/stdc++.h>
using namespace std;

int hammingBit(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return hammingBit(n>>1) + (n&1);
}

int main()
{
    int n;
    cin>>n;
    cout<<hammingBit(n)<<endl;

return 0;
}