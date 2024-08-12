#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(const std::vector<int> &nums)
{
    int n = nums.size();               // The length of the array
    int expectedSum = n * (n + 1) / 2; // Sum of first n natural numbers (including 0)
    int actualSum = 0;

    // Calculate the sum of all elements in nums
    for (int num : nums)
    {
        actualSum += num;
    }

    // The missing number is the difference between expectedSum and actualSum
    return expectedSum - actualSum;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << findMissingNumber(nums) << endl;
    return 0;
}