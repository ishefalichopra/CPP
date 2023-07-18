#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long sum=0;
    long long maxi = arr[0];
    for(int i=0;i<n;i++){
        sum += arr[i];
        maxi = max(maxi,sum);
        if (sum < 0) {
          sum = 0;
          maxi = 0;
        }
    }
    return maxi;
    
}
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<maxSubarraySum(arr,n)<<endl;
return 0;
}