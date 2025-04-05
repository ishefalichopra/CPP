#include<bits/stdc++.h>
using namespace std;

void inertionSort(vector<int>&arr, int n){

    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    vector<int>arr = {5, 1, 4, 2, 8};
    int n = arr.size();
    inertionSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}