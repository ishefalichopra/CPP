#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 0)
        return;

    vector<vector<int>> buckets(n);

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    for (int i = 0; i < n; i++)
    {
        int index = (arr[i]-minVal)*n/range;
        if (index >= n)
            index = n - 1;
        buckets[index].push_back(arr[i]);
    }
   

    for (int i = 0; i < n; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[k++] = buckets[i][j];
        }
    }
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

    bucketSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}