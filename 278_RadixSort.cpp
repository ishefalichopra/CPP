#include <bits/stdc++.h>
using namespace std;

int getMax(const vector<int> &arr)
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

void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();

    vector<int> output(n);
    int count[10] = {0};

    // Store the count of didgits in count array
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] to get the real position of the elements in output array
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr)
{
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}