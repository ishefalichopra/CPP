#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    map<int,int>mpp;
    mpp[0]=1;
    int preSum=0, cnt=0;
    for(int i=0;i<arr.size();i++){
        preSum+=arr[i];
        int remove = preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
}
int main()
{

    int n, k;
    cin >> n >> k;
    vector < int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findAllSubarraysWithGivenSum(arr, k);
return 0;
}