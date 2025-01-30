#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&arr){
    int n = arr.size();
    int k = 0;
    for(int i=0;i<n;i++){
        k ^= arr[i]^i;
    }
    k ^= n;
    return k;
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
    cout<<missingNumber(arr);

return 0;
}