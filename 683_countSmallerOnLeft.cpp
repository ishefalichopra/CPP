#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>> &vec, int left, int mid, int right, vector<int> &ans)
{
    vector<pair<int, int>> v;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (vec[i].first <= vec[j].first)
        {
            v.push_back(vec[j++]);
        }
        else
        {
            ans[vec[i].second] += (right - j + 1);
            v.push_back(vec[i++]);
        }
    }

    while (i <= mid)
    {
        v.push_back(vec[i++]);
    }

    while (j <= right)
    {
        v.push_back(vec[j++]);
    }

    for (int k = left; k <= right; k++)
    {
        vec[k] = v[k - left];
    }
}

void mergeSort(vector<pair<int, int>> &vec, int left, int right, vector<int> &ans)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid, ans);
    mergeSort(vec, mid + 1, right, ans);
    merge(vec, left, mid, right, ans);
}

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(nums.size(), 0);
    vector<pair<int, int>> vec(nums.size());
    for (int i = 0; i < n; ++i)
        vec[i] = {nums[i], i};
    mergeSort(vec, 0, n - 1, ans);
    return ans;
}

int main()
{

    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}