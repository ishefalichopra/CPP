
#include <bits/stdc++.h>
using namespace std;
int omit2(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < (n - 2); i++)
    {
        cout << arr[i];
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
     omit2(arr, n);
   

    return 0;
}