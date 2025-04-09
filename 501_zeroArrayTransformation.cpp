#include<bits/stdc++.h>
using namespace std;

bool isZeroArray(vector<int>&nums, vector<vector<int>>&queries) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);
    for(int i=0;i<queries.size();i++){
        int a = queries[i][0];
        int b = queries[i][1];
        prefixSum[a] += 1;
        while(b+1<n){
            prefixSum[b+1] -= 1;
        }
    }
    int curr = 0;
    for(int i=0;i<n;i++){
        curr += prefixSum[i];
        int dec = min(curr, nums[i]);
        nums[i] -= dec;
    }

    for(int i=0;i<n;i++){
        if(nums[i] != 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i=0;i<q;i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    
    if(isZeroArray(nums, queries)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

return 0;
}