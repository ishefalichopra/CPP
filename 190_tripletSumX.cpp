#include<bits/stdc++.h>
using namespace std;

bool findSum(int A[],int n, int X){
    sort(A,A+n);
    int j,k;
    for(int i=0;i<n-2;i++){
        j=i+1;
        k=n-1;
        while(j<k){
            if(A[i]+A[j]+A[k]==X){
                return true;
            }
            else if(A[i]+A[j]+A[k]<X){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;++i){
        cin >> A[i];
    }
    int X;
    cin >> X;
    cout << findSum(A,n,X) << endl;

return 0;
}