#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
bool isToeplitz(int a[MAX][MAX], int n, int m){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]!=a[i+1][j+1]){
                return false;
            }
        }
    }
    return true;
}
int main()
{
int n,m;
cin>>n>>m;
int a[MAX][MAX];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
if(isToeplitz(a, n, m)){
    cout<<"Yes";
}
else{
    cout<<"No";
}
return 0;
}