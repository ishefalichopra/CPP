#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int num: nums){
        ans ^= num;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n; // Input the size of the array
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i]; // Input the elements of the array
    }
    cout << singleNumber(nums) << endl; // Output the single number that appears only once

return 0;
}