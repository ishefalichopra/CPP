#include <bits/stdc++.h>
using namespace std;

int pairWithMaxSum(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return -1;
    int maxSum = INT_MIN;

    for (int i = 0; i < n - 1; i++)
    {
        maxSum = max(maxSum, arr[i] + arr[i + 1]);
    }
    return maxSum;
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
    cout << pairWithMaxSum(arr);

    return 0;
}