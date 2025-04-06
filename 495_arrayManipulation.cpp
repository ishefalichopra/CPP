#include<bits/stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>>&queries){
    vector<int>arr(n+2,0);

    for(int i=1;i<queries.size();i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;
        arr[b+1] -= k;
    }

    long maxi = 0, prefixSum = 0;

    for(int i=1;i<=n;i++){
        prefixSum += arr[i];
        maxi = max(maxi, prefixSum);
    }
    return maxi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> queries(m, vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin >> queries[i][j];
        }
    }

    cout << arrayManipulation(n, queries) << endl;

return 0;
}