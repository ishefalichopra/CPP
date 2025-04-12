#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    int n = nums.size();
    int x = 1<<n; // 2^n subsets
    vector<vector<int>> ans;
    for(int i=0;i<x;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
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
    vector<vector<int>> result = subsets(nums); // Get all subsets
    for(auto subset : result){
        cout << "{ ";
        for(int num : subset){
            cout << num << " "; // Output each subset
        }
        cout << "}" << endl;
    }

return 0;
}