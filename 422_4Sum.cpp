#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    if (n < 4)
        return ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {

        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1, l = n - 1;

            while (k < l)
            {
                long long sum =
                    (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> ans = fourSum(nums, target);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }

    return 0;
}