#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }
    for (auto &x : hash)
    {
        if (x.second > n / 2)
        {
            return x.first;
        }
    }

    return 0;
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
    cout << majorityElement(nums);

    return 0;
}