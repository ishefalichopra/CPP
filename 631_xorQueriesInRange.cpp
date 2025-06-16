#include<bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
    int n = arr.size();
    vector<int>pre(n, 0);
    pre[0] = arr[0];

    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]^arr[i];
    }

    vector<int> ans;
    for(auto& q: queries){
        int l = q[0], r = q[1];
        int res = 0;
        if(l > 0){
            res ^= pre[l-1];
        }
        res ^= pre[r];
        ans.push_back(res);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

    vector<int> result = xorQueries(arr, queries);
    for(int res : result){
        cout << res << " ";
    }
    cout << endl;

return 0;
}