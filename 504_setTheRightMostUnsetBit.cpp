#include<bits/stdc++.h>
using namespace std;

int setBits(int n){
    int x = n;
    while(x&1 != 0){
        x = x>>1;
    }
    if(x == 0) return n;
    return n|(n+1);
}

int main()
{
    int n;
    cin>>n;
    cout<<setBits(n)<<endl;

return 0;
}