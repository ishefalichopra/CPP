#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> &ans, vector<bool> &visited, vector<vector<int>> &result)
{
    if (ans.size() == nums.size())
    {
        result.push_back(ans);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i])
            continue;
        ans.push_back(nums[i]);
        visited[i] = true;
        solve(nums, ans, visited, result);
        visited[i] = false;
        ans.pop_back();
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ans;
    vector<vector<int>> result;
    vector<bool> visited(nums.size(), false);
    solve(nums, ans, visited, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for (const auto &perm : result)
    {
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}