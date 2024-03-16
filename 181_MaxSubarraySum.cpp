#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[],int n){
    long long maxSum=INT_MIN;
    long long currentSum=0;

    for(int i=0;i<n;i++){
            
            currentSum += arr[i];
            maxSum= max(currentSum,maxSum);
            
            if(currentSum<0){
                currentSum=0;
            }
    }
    return maxSum;
}

int main()
{

    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    cout<<maxSubarraySum(arr,n);

return 0;
}