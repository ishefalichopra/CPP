#include<bits/stdc++.h>
using namespace std;

int findFrequency(vector<int>& nums, int target) {
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    int target;
    std::cin >> target;
    std::cout << "Frequency of " << target << " is: " << findFrequency(nums,target) << std::endl;

return 0;
}