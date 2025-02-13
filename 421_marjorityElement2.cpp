#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> hash;
    vector<int> ans;
    int n = nums.size();
    for (int num : nums)
    {
        hash[num]++;
    }
    for (auto &num : hash)
    {
        if (num.second > n / 3)
        {
            ans.push_back(num.first);
        }
    }
    sort(ans.begin(), ans.end());
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
    vector<int> ans = majorityElement(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}