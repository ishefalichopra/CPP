#include <bits/stdc++.h>
using namespace std;

int computeCost(int arr[], int n, int x)
{
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(arr[i] - x);
    }
    return cost;
}

int minCostToMakeElementEqual(int arr[], int n)
{
    int low, high;
    low = high = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }

    while ((high - low) > 2)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        int cost1 = computeCost(arr, n, mid1);
        int cost2 = computeCost(arr, n, mid2);

        if (cost1 < cost2)
            high = mid2;
        else
            low = mid1;
    }

    return computeCost(arr, n, (low + high) / 2);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum cost to make all elements equal is: " << minCostToMakeElementEqual(arr, n);
    

    return 0;
}