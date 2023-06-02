#include<bits/stdc++.h>
using namespace std;
int FindAllDuplicates(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<" ";
            }
        }
    }
    return 0;
}
int main()
{
    int n;  cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    FindAllDuplicates(arr,n);

return 0;
}