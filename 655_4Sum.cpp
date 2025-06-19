#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i <= n - 4; i++)
    {
        for (int j = i + 1; j <= n - 3; j++)
        {
            long long needed = (long long)target - (nums[i] + nums[j]);
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == needed)
                {
                    st.insert({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < needed)
                    l++;
                else
                    r--;
            }
        }
    }

    for (auto &it : st)
    {
        ans.push_back(it);
    }
    return ans;
}

int main()
{

    vector<int> nums = {0, -2, 2, 1, -1, 0};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for (auto &v : ans)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}