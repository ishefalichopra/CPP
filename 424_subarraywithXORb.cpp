#include<bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n = a.size();
    map<int,int>mp;
    int cnt = 0;
    int sub=0;

    for(int i=0;i<n;i++){
       sub ^= a[i];

       if(sub == b)cnt++;
       if(mp.find(sub^b) != mp.end()){
           cnt += mp[sub^b];
       }
       mp[sub]++;
    }
    return cnt;
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b;
    cin>>b;
    int ans = subarraysWithSumK(a,b);
    cout<<ans;

return 0;
}