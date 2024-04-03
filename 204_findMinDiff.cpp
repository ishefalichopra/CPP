#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long>arr, long long n, long long m){
    sort(arr.begin(), arr.end());
    long long ans = INT_MAX;
    for(long long i=0;i+m-1<n;++i){
        ans = min(ans, arr[i+m-1]-arr[i]);
    }
    return ans;
}

int main()
{
    long long n,m;
    cin >> n >> m;
    vector<long long>a(n);
    for(long long i=0;i<n;++i){
        cin >> a[i];
    }
    cout << findMinDiff(a,n,m) << endl;

return 0;
}