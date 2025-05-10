#include<bits/stdc++.h>
using namespace std;

int maximum(vector<int>& arr){
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>&arr, int exp){
    int n = arr.size();
    int count[10] = {0};
    vector<int>output(n);

    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr){
    int maxi = maximum(arr);
    for(int exp = 1; maxi/exp >0; exp*=10){
        countingSort(arr, exp);
    }
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

    radixSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}