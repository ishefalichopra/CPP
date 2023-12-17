/*
Given an array of intergers arr, return true if the number of occurences 
of each value in the array is unique, or false otherwise. 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;  cin>>n;
int arr[n];
for(int i=0;i<n;i++)    cin>>arr[i];
map<int,int> mp;
for(int i=0;i<n;i++)    mp[arr[i]]++;
map<int,int>::iterator it;
for(it=mp.begin();it!=mp.end();it++)
{
    if(it->second>1)
    {
        cout<<"false"<<endl;
        return 0;
    }
}
cout<<"true"<<endl;

return 0;
}