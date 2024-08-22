#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>&nums){
    int n=nums.size();
    int s=0;
    int e=n-1;
    while(s<e){
        int mid = s+(e-s)/2;
        if(nums[mid]>nums[mid+1]){
            e=mid;
        }else{
            s=mid+1;
        }
    }
    return s;
}

int main()
{
    vector<int>nums={1,2,3,1};
    cout<<findPeakElement(nums)<<endl;

return 0;
}