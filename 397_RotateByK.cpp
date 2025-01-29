#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || k<0)return;
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        }

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums,k);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

return 0;
}