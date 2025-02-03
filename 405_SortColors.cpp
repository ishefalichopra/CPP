#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            x++;
        else if (nums[i] == 1)
            y++;
        else
            z++;
    }
    int j = 0;
    while (x--)
    {
        nums[j++] = 0;
    }
    while (y--)
    {
        nums[j++] = 1;
    }
    while (z--)
    {
        nums[j++] = 2;
    }
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
    sortColors(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}