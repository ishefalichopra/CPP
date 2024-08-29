#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<pair<int, int>> &num_idx, vector<int> &result,
               int left, int right)
{

    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(num_idx, result, left, mid);
    mergeSort(num_idx, result, mid + 1, right);

    merge(num_idx, result, left, mid, right);
}

void merge(vector<pair<int, int>> &num_idx, vector<int> &result, int left,
           int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, int>> leftArr(n1);
    vector<pair<int, int>> rightArr(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = num_idx[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = num_idx[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    int rightCnt = 0;

    while (i < n1 && j < n2)
    {
        if (leftArr[i].first > rightArr[j].first)
        {
            num_idx[k] = rightArr[j];
            rightCnt++;
            j++;
            k++;
        }
        else
        {
            result[leftArr[i].second] +=
                rightCnt; // store the cnt of element for that idx
            num_idx[k] = leftArr[i];
            i++;
            k++;
        }
    }

    while (i < n1)
    {
        result[leftArr[i].second] += rightCnt;
        num_idx[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        num_idx[k] = rightArr[j];
        j++;
        k++;
    }
}

vector<int> countSmaller(vector<int> &nums)
{

    int n = nums.size();
    vector<int> result(n, 0);
    vector<pair<int, int>> num_idx;

    for (int i = 0; i < n; i++)
    {
        num_idx.push_back({nums[i], i});
    }

    mergeSort(num_idx, result, 0, n - 1);

    return result;
}

int main()
{
    vector<int> arr = {5, 2, 6, 1};
    vector<int> res = countSmaller(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}