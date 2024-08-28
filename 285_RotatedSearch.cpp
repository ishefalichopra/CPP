#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                if ((nums[low] <= target) && (target < nums[mid])) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if ((nums[mid] < target) && (target <= nums[high])) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }

int main()
{
    vector<int>arr={4,5,6,7,0,1,2};
    int target = 0;
    cout<<search(arr,0)<<endl;

return 0;
}