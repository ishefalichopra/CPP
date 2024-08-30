#include <bits/stdc++.h>
using namespace std;

int getSubArrayCount(vector<int> &nums, int maxSumLimit)
{
    int subArrayCnt = 1;

    long long currsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (currsum + nums[i] <= maxSumLimit)
        {
            currsum += nums[i];
        }
        else
        {
            subArrayCnt++;
            currsum += nums[i];
        }
    }
    return subArrayCnt;
}

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
        return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int subArrayCnt = getSubArrayCount(nums, mid);

        if (subArrayCnt <= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(arr, k);

    return 0;
}