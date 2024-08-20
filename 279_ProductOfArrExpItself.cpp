#include <bits/stdc++.h>
using namespace std;

void productArray(int arr[], int n)
{

    if (n == 1)
    {
        cout << 0;
        return;
    }

    int *prefix = new int[n];
    int *suffix = new int[n];
    int *prod = new int[n];

    int i, j;

    prefix[0] = 1;
    suffix[n - 1] = 1;

    for (i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    for (j = n - 2; j >= 0; j--)
    {
        suffix[j] = suffix[j + 1] * arr[j + 1];
    }

    for (i = 0; i < n; i++)
    {
        prod[i] = prefix[i] * suffix[i];
    }

    for (i = 0; i < n; i++)
    {
        cout << prod[i] << " ";
    }

    return;
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);

    return 0;
}