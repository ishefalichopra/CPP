#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
        }
        return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<largest(arr)<<endl;

return 0;
}