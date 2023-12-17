#include<bits/stdc++.h>
using namespace std;
    int subarrayZero(vector<int>& nums) {
    // Write your code here
    int n= nums.size();
    unordered_map<int,int>mp;
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==0){
            maxi =i+1;
        }
        if(mp.find(sum)!=mp.end()){
            maxi = max(maxi,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }
        mp[sum]=i;
    }
    return (int)maxi;
}
int main()
{
    int n;
    cin>>n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = subarrayZero(v);
    cout<<ans<<endl;
return 0;
}