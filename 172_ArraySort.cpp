#include<bits/stdc++.h>
using namespace std;

vector<int> sortArray(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return nums;
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
    vector<int> ans = sortArray(nums);
    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << " ";
    }

return 0;
}