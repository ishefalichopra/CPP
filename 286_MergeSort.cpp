#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int left, int mid, int right){
    int n1= mid-left+1;
    int n2= right-mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for(int i=0;i<n1;i++){
        leftArr[i]= arr[left+i];
    }
    for(int i=0;i<n2;i++){
        rightArr[i]= arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=left;

    while(i<n1&&j<n2){
        if(leftArr[i]<=rightArr[j]){
            arr[k]=leftArr[i];
            i++;
        }
        else{
            arr[k]= rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=leftArr[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>&arr, int left, int right){
    if(left>=right){
        return;
    }
    int mid= left+(right-left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n= arr.size();
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}