#include<bits/stdc++.h>
using namespace std;
int arrayPrint(int a[], int n){
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
return 0;
}
int SwapAlternate(int a[], int n){
    int temp=0;
    for(int i=0;i<n;i+=2){
        if(i+1<n){
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
        }
    }
    return 0;
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
arrayPrint(a, n);
SwapAlternate(a, n);
arrayPrint(a, n);
return 0;
}