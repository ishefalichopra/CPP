#include <bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &arr, int n)
{
    // Write your code here.

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[temp])
        {
            arr[temp] = arr[i];
        }
    }
    int largest = arr[temp];
    return largest;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << largestElement(arr, n);

    return 0;
}