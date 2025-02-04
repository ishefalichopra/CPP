#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    // Code here
    vector<int> ans;
    int n = arr.size();
    int currMax = arr[n - 1];
    ans.push_back(currMax);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= currMax)
        {
            currMax = arr[i];
            ans.push_back(currMax);
        }
    }
    reverse(ans.begin(), ans.end());
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
    vector<int> ans = leaders(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}