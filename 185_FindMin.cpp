#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n){
        sort(arr,arr+n);
        return arr[0];
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
    cout << findMin(arr, n);

return 0;
}