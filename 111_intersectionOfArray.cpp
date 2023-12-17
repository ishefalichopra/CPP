#include<bits/stdc++.h>
using namespace std;
int FindIntersection(int arr1[], int arr2[], int n, int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }
        if(arr1[i]>arr2[j]){
            j++;
        }
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }

    return 0;
}
int main()
{
    int n,m;  cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)    cin>>arr1[i];
    for(int i=0;i<m;i++)    cin>>arr2[i];
    FindIntersection(arr1,arr2,n,m);

return 0;
}