#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
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
    cout << singleNumber(nums);

    return 0;
}