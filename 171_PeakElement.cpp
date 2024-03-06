#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[],int n){
    int start=0;
    int end=n-1;

    while(start<end){
        int mid = start + (end-start)/2;
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    
    return start;   
}

int main()
{

    int n;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    std::cout << "Peak Element is: " << peakElement(a,n) << std::endl;
return 0;
}