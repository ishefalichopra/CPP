#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
 vector<int> getMoreandLess(int arr[], int n, int x){
vector<int> ans;
int c8=0;
int cnt=0;
for(int i=0; i<n ; i++){
    if(arr[i]<=x){
        cnt++;
    }
     if(arr[i]>=x){
        c8++;
    }
    ans.push_back(cnt);
    ans.push_back(c8);
    return ans;
}
 }
};
int main()
{

    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    Solution ob;
    auto ans =ob.getMoreandLess(arr,n,x);
    cout<<ans[0]<<" "<<ans[1]<<endl;


return 0;
}