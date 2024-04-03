#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> stockBuySell(vector<int> a,int n){
    vector<vector<int>>ans;
    vector<int> b=a;
    sort(b.begin(),b.end(),greater<int>());
    if(b==a){
        return ans;
    }

    a.push_back(-1);
    int profit=0;
    int j=0;
    for(int i=0;i<=n;i++){
        if(a[i]<a[i+1]){
            profit+=(a[i+1]-a[i]);
        }
        else{
            ans.push_back(vector<int>{j,i});
            j=i+1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    vector<vector<int>>res = stockBuySell(a,n);
    for(int i=0;i<res.size();++i){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    cout << endl;

return 0;
}