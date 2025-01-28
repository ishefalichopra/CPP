#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = right - mid;
    int n2 = mid - left + 1;

    vector<int> L(n2), R(n1);

    for (int i = 0; i < n2; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n1; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n2 && j < n1)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n2)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n1)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    // code here
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}