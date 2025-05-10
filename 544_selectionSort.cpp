#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        int minIndex = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
}

void selectionSortRecursive(vector<int>& arr, int n, int index){
    if(index == n-1)
        return;

    int minIndex = index;
    for(int j=index+1;j<n;j++){
        if(arr[j]<arr[minIndex]){
            minIndex = j;
        }
    }
    if(minIndex != index){
        swap(arr[index], arr[minIndex]);
    }
    selectionSortRecursive(arr, n, index+1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}