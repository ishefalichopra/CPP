#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr, int n){

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main()
{
    vector<int>arr = {5, 1, 4, 2, 8};
    int n = arr.size();
    bubbleSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}