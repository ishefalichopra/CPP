#include <iostream>
using namespace std;
int print2largest(int arr[], int n)
{
    int max = INT_MIN;
    int secondmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            secondmax = max;
            arr[i] = max;
        }
        if ((secondmax < arr[i])&&(arr[i]<max))
        {
            secondmax = arr[i];
        }
        
    }
    if ((secondmax<INT_MIN/10)||(secondmax>INT_MAX/10))
    {
        return -1;
    }
    return secondmax;
}
int main()
{
    int arr[5] = {3, 4, 6, 7, 9};
    int ans = print2largest(arr,5);
    cout<<ans;
    return 0;
}