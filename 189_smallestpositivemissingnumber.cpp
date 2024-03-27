#include<bits/stdc++.h>
using namespace std;


int missingNumber(int arr[],int n){
    for(int i=0;i<n;){
        if(arr[i]<=0||arr[i]>n){
            arr[i]=0;
            ++i;
        }
        else{
            if(arr[i]==arr[arr[i]-1]){
                ++i;
                continue;
            }
            swap(arr[i],arr[arr[i]-1]);
        }
    }
    for(int i=0;i<n;++i){
        if(arr[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    cout << missingNumber(arr,n) << endl;

return 0;
}