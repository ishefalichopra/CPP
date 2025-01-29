#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>&nums){
    int n = nums.size();
    int j=0;
    if(n==0){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=nums[j]){
            j++;
            nums[j]=nums[i];
        }
    }
    return j+1;
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
    cout << removeDuplicates(arr) << endl;

return 0;
}