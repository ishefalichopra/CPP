#include<bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashh; // Map to store number and its index
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (hashh.find(complement) != hashh.end()) {
            ans.push_back(hashh[complement]); // Index of the complement
            ans.push_back(i);                // Current index
            return ans;
        }
        hashh[nums[i]] = i; // Store the current number and its index
    }

    return ans; // Return an empty vector if no solution is found
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

return 0;
}