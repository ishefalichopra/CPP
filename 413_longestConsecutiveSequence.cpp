#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    unordered_set<int> hashh(nums.begin(), nums.end());

    int cnt = 0;

    for (int num : nums)
    {
        if (!hashh.count(num - 1))
        {
            int curr = num;
            int streak = 1;

            while (hashh.count(curr + 1))
            {
                curr++;
                streak++;
            }
            cnt = max(cnt, streak);
        }
    }

    return cnt;
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
    cout << longestConsecutive(nums);

    return 0;
}