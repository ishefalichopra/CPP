#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>>arr, int n, int m){
    int r=0;
    int c=m-1;
    int ans=-1;
    for(int i=0;i<n;i++){
        while(r<n&&c>=0){
            if(arr[r][c]==1){
                ans=r;
                c--;
            }
            else{
                r++;
            }
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> arr[i][j];
        }
    }
    cout << rowWithMax1s(arr,n,m) << endl;

return 0;
}