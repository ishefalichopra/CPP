#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);

    int pIndex = 0, nIndex = 1;
    for (int num : nums)
    {
        if (num > 0)
        {
            ans[pIndex] = num;
            pIndex += 2;
        }
        else
        {
            ans[nIndex] = num;
            nIndex += 2;
        }
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
    vector<int> ans = rearrangeArray(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}