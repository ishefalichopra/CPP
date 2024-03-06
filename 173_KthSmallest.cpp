#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[],int l, int r,int k){
    int n=r+1;
    sort(arr,arr+n);
    return arr[k-1];
}

int main()
{

    int n;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    int k;
    std::cin >> k;
    std::cout << "Kth Smallest Element is: " << kthSmallest(a,0,n-1,k) << std::endl;

return 0;
}