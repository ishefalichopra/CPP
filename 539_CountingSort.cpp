#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr, int n, int k)
{
    vector<int> temp(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    int j = 0;
    for (int i = 0; i <= k; i++)
    {

        while (temp[i] > 0)
        {
            arr[j] = i;
            j++;
            temp[i]--;
        }
    }
}

int findMax(vector<int> &arr)
{
    int maxi = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
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
    int k = findMax(arr);
    countingSort(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}