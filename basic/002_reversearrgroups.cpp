#include <iostream>
#include <vector>
using namespace std;
void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void reverseInGroups(int arr[], int n, int k)
{
    int i = 0;
    while (i + k <= n)
    {
        reverse(arr, i, i + k - 1);
        i += k;
    }
    if (i < n)
    {
        reverse(arr, i, n - 1);
    }
}
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    int k;
    cin >> k;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " "<<endl;

    reverseInGroups(arr, 5, k);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " "<<endl;

    return 0;
}