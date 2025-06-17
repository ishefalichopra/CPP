#include <bits/stdc++.h>
using namespace std;

long long subarraySum(vector<int> &arr)
{
    long long ans = 0, n = arr.size();
    const int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        long long left = i + 1;
        long long right = n - i;
        long long contribution = ((left * right) % MOD * arr[i]) % MOD;
        ans = (ans + contribution) % MOD;
    }
    return ans;
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
    cout << subarraySum(arr) << endl;
    

    return 0;
}