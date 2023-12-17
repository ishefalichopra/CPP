#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0&&arr[j-1]<arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main()
{
int n;
cin >> n;
int *arr = new int[n];
for(int i = 0; i < n; i++)
cin >> arr[i];
insertionSort(arr,n);
for(int i = 0; i < n; i++)
cout << arr[i] << " ";
delete[] arr;


return 0;
}