#include<bits/stdc++.h>
using namespace std;
int countofelements(int arr[], int n, int x)
{
int count =0;
int i=0;
while((arr[i]==x||arr[i]<x)&&i<n)
{
    count += 1;
    i++;
}
return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            /* code */
            cin>>arr[i];
            
        }

        cin>>x;
    cout<<countofelements(arr,n,x)<<endl;
    }
    

return 0;
}