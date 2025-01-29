#include<bits/stdc++.h>
using namespace std;
int secondLargest(vector<int>&arr){
    int n = arr.size();
    int largest = INT_MIN, secondLargest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]!=largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest==INT_MIN?-1:secondLargest;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<secondLargest(arr)<<endl;

return 0;
}