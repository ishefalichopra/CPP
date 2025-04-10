#include<bits/stdc++.h>
using namespace std;

vector<int> countBits(int n){
    vector<int>ans(n+1);
    for(int i=0;i<=n;i++){
        ans[i] = ans[i>>1] + (i&1);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>ans = countBits(n);
    for(int i=0;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

return 0;
}
