#include <bits/stdc++.h>
using namespace std;

int min(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[0];
}
int minMoves(vector<int> &nums)
{

    int min_num = min(nums);

    int moves = 0;
    for (int num : nums)
    {
        moves += num - min_num;
    }

    return moves;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << minMoves(nums) << endl;
    return 0;
}