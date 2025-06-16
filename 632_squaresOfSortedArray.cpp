#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> ans(n);
    int k = n - 1;
    while (l <= r)
    {
        if (abs(nums[l]) < abs(nums[r]))
        {
            ans[k--] = nums[r] * nums[r];
            r--;
        }
        else
        {
            ans[k--] = nums[l] * nums[l];
            l++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}