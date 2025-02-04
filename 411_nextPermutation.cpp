#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i])
                pos = i - 1;
        }

        if (pos != -1) {
            for (int i = n-1; i > pos; i--) {
                if (nums[pos] < nums[i]) {
                    swap(nums[pos], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin() + pos + 1, nums.end());
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
    nextPermutation(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

return 0;
}