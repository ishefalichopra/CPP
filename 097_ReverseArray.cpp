#include<bits/stdc++.h>
using namespace std;
int reverse(int a[], int n){
    int temp=0;
    for(int i=0;i<=(n/2);i++){
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    return 0;
}
int arrayPrint(int a[], int n){
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
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
reverse(a, n);
arrayPrint(a, n);


return 0;
}