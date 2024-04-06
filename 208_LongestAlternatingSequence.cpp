#include<bits/stdc++.h>
using namespace std;

int longestAlternatingSequence(int arr[],int n)
{
    int inc = 1,dec = 1;
    for(int i=1;i<n;++i){
        if(arr[i]>arr[i-1]){
            inc = dec + 1;
        }
        else if(arr[i]<arr[i-1]){
            dec = inc + 1;
        }
    }
    return max(inc,dec);
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    cout << longestAlternatingSequence(a,n) << endl;

return 0;
}