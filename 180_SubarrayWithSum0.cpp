#include<bits/stdc++.h>
using namespace std;

bool SubarrayExists(int arr[],int n){
    int sum=0;
    int ans=0;
    map<int,int>mp;

    for(int i=0;i<n;i++){
        sum+= arr[i];
        if(sum==0) return true;

        if(mp.find(sum)!=mp.end())return true;
        else mp[sum]=i;
    }
    return false;
}

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    if(SubarrayExists(arr,n)) cout<<"Yes";
    else cout<<"No";

return 0;
}