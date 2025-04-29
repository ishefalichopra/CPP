#include <bits/stdc++.h>
using namespace std;

// 1 2 3 1 4 5
// o/p : -1,1,1,-1,-1,-1

vector<int> nextSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    stack<int> s;

    for (int num : nums)
    {
        while (!s.empty() && num < s.top())
        {
            mp[s.top()] = num;
            s.pop();
        }
        s.push(num);
    }

    while (!s.empty())
    {
        mp[s.top()] = -1;
        s.pop();
    }

    vector<int> ans;
    for (int num : nums)
    {
        ans.push_back(mp[num]);
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
    vector<int> ans = nextSmallerElement(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}