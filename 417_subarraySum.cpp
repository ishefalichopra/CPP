#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> hashh;
    int sum = 0;
    int cnt = 0;

    hashh[0] = 1;

    for (int num : nums)
    {
        sum += num;
        if (hashh.find(sum - k) != hashh.end())
        {
            cnt += hashh[sum - k];
        }
        hashh[sum]++;
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
    int k;
    cin >> k;
    cout << subarraySum(nums, k);

    return 0;
}