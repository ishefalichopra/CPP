#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSum(vector<int> a, long long k)
{
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += a[right];
    }
    return maxLen;
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
    long long k;
    cin >> k;
    cout << longestSubarrayWithSum(arr, k);
    return 0;
}