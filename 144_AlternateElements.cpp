#include<bits/stdc++.h>
using namespace std;
vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    int n= a.size();
    vector<int>ans(n,0);
    int pI=0, nI=1;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            ans[nI]=a[i];
            nI+=2;
        }
        else{
            ans[pI]=a[i];
            pI+=2;
        }
    }
    return ans;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans=alternateNumbers(a);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    

return 0;
}