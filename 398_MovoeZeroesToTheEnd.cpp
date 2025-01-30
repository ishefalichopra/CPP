#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    while (j < n)
    {
        nums[j] = 0;
        j++;
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
    moveZeroes(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}