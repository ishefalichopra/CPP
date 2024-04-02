#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>arr , int n){
    vector<int>ans;

    unordered_map<int,int>mp;

    for(int i=0;i<n;++i){
        mp[arr[i]]++;
    }

    for(int i=1;i<=n;++i){
        if(mp.find(i)==mp.end()){
            ans.push_back(i);
        }
        if(mp[i]>1){
            ans.insert(ans.begin(),i);
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
    vector<int>res = findTwoElement(a,n);
    for(int i=0;i<res.size();++i){
        cout << res[i] << " ";
    }
    cout << endl;

return 0;
}