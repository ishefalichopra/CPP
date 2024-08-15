#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    int i=0,j=1;

    while(i<size && j<size)
    {
        if(i!=j && (arr[j]-arr[i]==n)||(arr[i]-arr[j]==n))
        {
            cout<<"Pair found ("<<arr[i]<<","<<arr[j]<<")";
            return true;
        }
        else if(arr[j]-arr[i]<n)
            j++;
        else
            i++;
    }
    cout<<"Pair not found";
    return false;
}

int main()
{   
    int arr[] = {1, 8, 30, 40, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 60;
    findPair(arr, size, n);
    return 0;
}