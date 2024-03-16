#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int arr[], int n)
{
    long long maxProduct = arr[0];
    long long minProduct = arr[0];
    long long result = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxProduct, minProduct);
        }
        maxProduct = max((long long)arr[i], maxProduct * arr[i]);
        minProduct = min((long long)arr[i], minProduct * arr[i]);
        result = max(result, maxProduct);
    }
    return result;
}

int main()
{

    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    cout << maxProduct(arr, n);

    return 0;
}