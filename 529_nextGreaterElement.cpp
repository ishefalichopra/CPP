#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int>mp;
    stack<int>s;

    for(int num: nums2){
        while(!s.empty() && num > s.top()){
            mp[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    while(!s.empty()){
        mp[s.top()] = -1;
        s.pop();
    }

    vector<int>ans;
    for(int num: nums1){
        ans.push_back(mp[num]);
    }
    return ans;
}

int main()
{
    int n, m;
    cin>>n;
    cin>>m;
    vector<int>nums1(n);
    vector<int>nums2(m);
    
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }

    vector<int>ans = nextGreaterElement(nums1, nums2);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

return 0;
}