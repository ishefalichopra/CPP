#include<bits/stdc++.h>
using namespace std;

long long smallestPositiveNo(vector<long long> arr,int N)
{
    sort(arr.begin(),arr.end());
    long long res = 1;
    for(int i=0;i<N && arr[i]<=res;++i){
        res += arr[i];
    }
    return res;
  
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    vector<long long> arr(a,a+n);
    cout << smallestPositiveNo(arr,n) << endl;

return 0;
}