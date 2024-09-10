#include <bits/stdc++.h>
using namespace std;

long long findMaximumScore(vector<int> &nums)
{
    long long ans = 0;
    int i = 0, j = i + 1;
    int n = nums.size(), f = 0;
    while (i < j && j < n)
    {
        if (nums[j] > nums[i])
        {
            ans += (long long)nums[i] * (long long)(j - i);
            i = j;
        }
        if (i < nums.size() && j == n - 1)
        {
            ans += (long long)nums[i] * (long long)(j - i);
            i = j;
        }
        j++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << findMaximumScore(nums);

    return 0;
}