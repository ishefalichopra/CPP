#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>&a,int N){
    int xor1=0;
    for(int i=0;i<N;i++){
        xor1= xor1^a[i];
    }
    return xor1;
}
int main()
{
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++)
cin >> arr[i];
cout<<singleNumber(arr,n);

return 0;
}