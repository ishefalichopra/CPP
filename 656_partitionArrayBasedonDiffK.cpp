#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int cnt = 0;
    int i = 0, j = i + 1;
    while (i < n && j < n)
    {
        if (nums[j] - nums[i] <= k)
        {
            j++;
        }
        else
        {
            cnt++;
            i = j;
            j++;
        }
    }
    if (i < n)
        cnt++;
    return cnt;
}

int main()
{
    vector<int> nums = {1, 3, 6, 2, 5};
    int k = 2;

    int result = partitionArray(nums, k);
    cout << "Number of partitions: " << result << endl;



    return 0;
}