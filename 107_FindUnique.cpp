#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int res=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        res=res^arr[i];
    }
    cout<<res<<endl;

return 0;
}