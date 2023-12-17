#include<bits/stdc++.h>
using namespace std;
#include<vector>
void merge(long long a[], long long b[], int n, int m){
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(a[left]>b[right]){
            swap(a[left], b[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(a, a+n);
    sort(b, b+m);
}
int main()
{
int n;
cin>>n;
int m;
cin>>m;
long long a[n];
long long b[m];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<m;i++){
    cin>>b[i];
}
merge(a, b, n, m);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
for(int i=0;i<m;i++){
    cout<<b[i]<<" ";
}

return 0;
}