#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    map<int, int> hashh;

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];

        if (hashh.find(complement) != hashh.end())
        {
            ans.push_back(hashh[complement]);
            ans.push_back(i);
            break;
        }
        hashh[nums[i]] = i;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    vector<int> ans = twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}