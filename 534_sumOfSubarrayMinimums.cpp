#include<bits/stdc++.h>
using namespace std;

int minSumSubarray(vector<int>& arr){
    int n = arr.size();
    stack<int>s;
    vector<int> prev(n), next(n);

    for(int i=0;i<n;i++){
        while(!s.empty() && arr[i] < arr[s.top()]){
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while(!s.empty()) s.pop();

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    long long sum = 0, mod = 1e9+7;
    for(int i=0;i<n;i++){
        long long left = i - prev[i];
        long long right = next[i] - i;
        sum = (sum + arr[i]*left*right) % mod;
    }
    return sum;
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
    cout<<minSumSubarray(arr);
return 0;
}