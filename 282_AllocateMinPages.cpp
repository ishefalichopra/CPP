#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, long long max_pages)
{
    int cnt = 1;
    long long currPages = 0;

    for (int i = 0; i < n; i++)
    {
        // if a single book has more pages than maxpages we cannot allocate it
        if (arr[i] > max_pages)
            return false;

        // If adding the book exceeds maxpages then allocate to the next student

        if (currPages + arr[i] > max_pages)
        {
            cnt++;
            currPages = arr[i];

            if (cnt > m)
                return false;
        }
        else
        {
            currPages += arr[i];
        }
    }
    return true;
}

long long findPages(int n, int arr[], int m)
{
    // code here
    if (n < m)
        return -1;

    long long low = *max_element(arr, arr + n);
    long long high = accumulate(arr, arr + n, 0LL);

    long long result = high;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int n = 4;
    int arr[] = {12, 34, 67, 90};
    int m = 2;
    cout << findPages(n, arr, m) << endl;

    return 0;
}