#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxEnding = nums[0], res = nums[0];
    int currSum = 0;

    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + nums[i], nums[i]);
        res = max(res, maxEnding);
    }
    return res;
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
    cout << maxSubArray(nums);

    return 0;
}