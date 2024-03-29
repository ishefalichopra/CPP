#include<bits/stdc++.h>
using namespace std;

void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i=0;i<n-1;i+=2){
           swap(arr[i],arr[i+1]);
        }
    }

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    convertToWave(n,arr);
    for(int i=0;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << endl;

return 0;
}