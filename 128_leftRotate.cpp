#include<bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    
    vector<int>temp(n);
   
    for(int i=1;i<n;i++){
       temp[i-1]= arr[i];
    }
    temp[n-1]=arr[0];
    
    
    return temp;
}

int main()
{
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++)
cin >> arr[i];
vector<int> ans = rotateArray(arr, n);
for(int i = 0; i < n; i++)
cout << ans[i] << " ";


return 0;
}