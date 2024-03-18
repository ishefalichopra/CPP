#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N)
{
    int cum_sum=0;
    for(int i=0;i<N;i++)
    {
        cum_sum+=A[i];
    }
    int initial_val=0;
    int max=0;
    for(int i=0;i<N;i++)
    {
        initial_val += i*A[i];
        max=initial_val;
    }
    for(int i=1;i<N;i++)
    {
        int temp = initial_val-(cum_sum-A[i-1])+A[i-1]*(N-1);
        initial_val=temp;
        if(temp>max)
            max=temp;
    }
    return max;
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
    cout << max_sum(arr, n);

return 0;
}