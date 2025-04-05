#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&  arr, int n, int low, int mid, int high){
    int i = low;
    int j = mid +1;
    vector<int> temp;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=low;k<=high;k++){
        arr[k] = temp[k-low];
    }
}
void mergeSort(vector<int>& arr, int n, int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(arr, n, low, mid);
        mergeSort(arr, n, mid+1, high);
        merge(arr, n, low, mid, high);
    }
}

int main()
{
    vector<int> arr = {5, 1, 4, 2, 8};
    int n = arr.size();
    mergeSort(arr,n,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}