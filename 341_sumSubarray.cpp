#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<pair<int, int>> s;

    // Calculate left array (how many subarrays end at each index where
    // arr[i] is the minimum)
    for (int i = 0; i < n; i++)
    {
        int cnt = 1; // Start with 1 (each element itself is a minimum in
                     // one subarray)
        while (!s.empty() && s.top().first > arr[i])
        {
            cnt += s.top().second;
            s.pop();
        }
        s.push({arr[i], cnt});
        left[i] = cnt;
    }

    // Clear the stack to reuse it
    while (!s.empty())
        s.pop();

    // Calculate right array (how many subarrays start at each index where
    // arr[i] is the minimum)
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 1; // Start with 1 (each element itself is a minimum in
                     // one subarray)
        while (!s.empty() && s.top().first >= arr[i])
        {
            cnt += s.top().second;
            s.pop();
        }
        s.push({arr[i], cnt});
        right[i] = cnt;
    }

    // Calculate the sum of all subarray minimums
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        long long contribution = (long long)arr[i] * left[i] * right[i];
        result = (result + contribution) % MOD;
    }

    return result;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMins(arr) << endl;

    return 0;
}
