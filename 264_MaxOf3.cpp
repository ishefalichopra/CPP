#include<bits/stdc++.h>
using namespace std;

 int maximumProduct(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int product = max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                          nums[0] * nums[1] * nums[n - 1]);

        return product;
    }

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << maximumProduct(nums) << endl;

return 0;
}