#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count = 0;
    while(n){
        count += n&1;
        n = n>>1;
    }
    cout<<count<<endl;

return 0;
}