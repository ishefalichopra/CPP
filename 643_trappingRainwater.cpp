#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& heights){
    int n = heights.size();
    vector<int> pre(n), suf(n);

    pre[0] = heights[0];
    for(int i = 1; i < n; i++){
        pre[i] = max(pre[i - 1], heights[i]);
    }

    suf[n - 1] = heights[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suf[i] = max(suf[i + 1], heights[i]);
    }

    int trappedWater = 0;

    for(int i=1;i<n-1;i++){
        int temp = min(pre[i], suf[i]);
        trappedWater += (temp - heights[i]) > 0 ? temp - heights[i] : 0;
    }
    return trappedWater;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }
    
    cout << trap(heights) << endl;

return 0;
}