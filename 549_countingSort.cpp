#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr, int k)
{
    vector<int> temp(k + 1, 0);
    for (int num: arr)
    {
        temp[num]++;
    }
    int j = 0;
    for (int i = 0; i <= k; i++)
    {
        while (temp[i]-- > 0)
        {
            arr[j++] = i;
        }
    }
}

int maximum(vector<int> &arr)
{
    int maxi = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
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
    int k = maximum(arr);

    countingSort(arr, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}