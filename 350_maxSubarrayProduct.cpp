#include<bits/stdc++.h>
using namespace std;

// int maxProductRecursive(vector<int>& nums, int i, int& result, int maxProd,
    //                         int minProd) {
    //     if (i == nums.size())
    //         return result;

    //     int currentMax =
    //         max(nums[i], max((nums[i] * maxProd), (nums[i] * minProd)));
    //     int currentMin =
    //         min(nums[i], min((nums[i] * maxProd), (nums[i] * minProd)));

    //     result = max(result, currentMax);

    //     return maxProductRecursive(nums, i + 1, result, currentMax, currentMin);
    // }

    // int memoMaxProduct(vector<int>& nums, int i, vector<vector<int>>& dp,
    //                    bool isMax) {
    //     if (i == nums.size())
    //         return 1;
    //     if (dp[i][isMax] != INT_MIN)
    //         return dp[i][isMax];

    //     int take =
    //         nums[i] * memoMaxProduct(nums, i + 1, dp, true); // Max product
    //     int leave =
    //         nums[i] * memoMaxProduct(nums, i + 1, dp, false); // Min product

    //     if (isMax) {
    //         return dp[i][isMax] = max(nums[i], max(take, leave));
    //     } else {
    //         return dp[i][isMax] = min(nums[i], min(take, leave));
    //     }
    // }

    // int maxProductTabulation(vector<int>& nums) {
    //     if (nums.empty())
    //         return 0;

    //     int n = nums.size();
    //     vector<int> maxProduct(n), minProduct(n);
    //     maxProduct[0] = minProduct[0] = nums[0];
    //     int result = nums[0];

    //     for (int i = 1; i < n; i++) {
    //         if (nums[i] < 0) {
    //             maxProduct[i] = max(nums[i], nums[i - 1] * nums[i]);
    //             minProduct[i] = min(nums[i], nums[i - 1] * nums[i]);

    //         } else {
    //             maxProduct[i] = max(nums[i], maxProduct[i - 1] * nums[i]);
    //             minProduct[i] = min(nums[i], minProduct[i - 1] * nums[i]);
    //         }
    //         result = max(result, maxProduct[i]);
    //     }

    //     return result;
    // }

    int maxProductSpaceOptimized(vector<int>& nums) {
        int maxProduct = nums[0], minProduct = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxProduct, minProduct);

            maxProduct = max(nums[i], maxProduct * nums[i]);
            minProduct = min(nums[i], minProduct * nums[i]);

            result = max(result, maxProduct);
        }

        return result;
    }
    int maxProduct(vector<int>& nums) { return maxProductSpaceOptimized(nums); }

int main()
{
    vector<int> nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;

return 0;
}