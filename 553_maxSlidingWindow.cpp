#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>&nums, int k){
    int n = nums.size();
    deque<int>dq;
    vector<int>ans;

    for(int i=0;i<n;i++){
        while(!dq.empty() && dq.front() >= i-k)
            dq.pop_front();

        while(!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(i);
        
        if(i >= k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<int> result = maxSlidingWindow(arr, k);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

return 0;
}