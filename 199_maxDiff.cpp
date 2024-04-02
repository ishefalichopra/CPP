#include<bits/stdc++.h>
using namespace std;


int maxDiff(int arr[],int n){
    if(n==1)
    return 0;

    int i,j,maxDiff;

    int *LMin = new int[n];
    int *RMax = new int[n];

    LMin[0] = arr[0];
    for(i=1;i<n;++i){
        LMin[i]= min(arr[i],LMin[i-1]);
    }

    RMax[n-1] = arr[n-1];
    for(j=n-2;j>=0;--j){
        RMax[j] = max(arr[j],RMax[j+1]);
    }

    i=0,j=0;
    maxDiff = -1;

    while(i<n&&j<n){
        if(LMin<=RMax){
            maxDiff = max(maxDiff,j-i);
            j++;
        }
        else
        i++;
    }
    return maxDiff;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    cout << maxDiff(a,n) << endl;

return 0;
}