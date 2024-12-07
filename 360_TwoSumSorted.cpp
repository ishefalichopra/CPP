#include<bits/stdc++.h>
using namespace std;
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<int> ans;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            ans.push_back(left);
            ans.push_back(right);
            return ans;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSumSorted(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

return 0;
}