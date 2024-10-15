#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    stack<int> s;

    for (int num : nums2)
    {
        while (!s.empty() && num > s.top())
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
    for (int num : nums1)
    {
        ans.push_back(mp[num]);
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}