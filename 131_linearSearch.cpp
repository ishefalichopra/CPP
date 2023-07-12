#include<bits/stdc++.h>
using namespace std;
int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }
        
    }
    return -1;
    
}

int main()
{
int n;
cin >> n;
vector<int> arr(n);
for(int i = 0; i < n; i++)
cin >> arr[i];
int num;
cin >> num;
cout << linearSearch(n, num, arr);

return 0;
}