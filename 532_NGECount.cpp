#include <bits/stdc++.h>
using namespace std;

vector<int> countGreater(vector<int> &arr, vector<int> &query)
{
    // Write your code here.
    vector<int> ans;
    int n = arr.size();
    for (int idx : query)
    {
        stack<int> s;
        for (int i = n - 1; i > idx; i--)
        {
            if (arr[i] > arr[idx])
            {
                s.push(arr[i]);
            }
        }
        ans.push_back(s.size());
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int m;
    cin >> m;
    vector<int> query(m);
    for (int i = 0; i < m; i++)
    {
        cin >> query[i];
    }
    vector<int> ans = countGreater(nums, query);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}