#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>&arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int minSwaps(vector<int> arr, int n){
    int ans=0;

    vector<int>temp = arr;
    map<int,int>h;

    sort(temp.begin(),temp.end());

    for(int i=0;i<n;i++){
        h[arr[i]]=i;
    }

    for(int i=0;i<n;i++){
        if(arr[i]!=temp[i]){
            ans++;
            int init = arr[i];
            swap(arr,i,h[temp[i]]);
            h[init]=h[temp[i]];
            h[temp[i]]=i;
        }
    }
    return ans;
}

int main()
{
    vector<int>arr={1,5,4,3,2};
    cout<<minSwaps(arr,arr.size())<<endl;

return 0;
}