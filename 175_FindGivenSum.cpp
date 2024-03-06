#include<bits/stdc++.h>
using namespace std;
//Find the indexes of an array with given sum
vector<int> findSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            ans.push_back(mp[target-nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]]=i;
    }
    return ans;
}
int main()
{
    int n;
    std::cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    int target;
    std::cin >> target;
    vector<int> ans = findSum(nums,target);
    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << " ";
    }

return 0;
}