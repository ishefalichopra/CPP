#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 0; i < 2 * n; i++)
    {
        int curr = nums[i % n];
        while (!s.empty() && curr > nums[s.top()])
        {
            ans[s.top()] = curr;
            s.pop();
        }

        if (i < n)
        {
            s.push(i);
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
    vector<int> ans = nextGreaterElement2(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}