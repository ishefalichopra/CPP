#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>&temperatures){
    int n = temperatures.size();
    vector<int> ans(n,0);
    stack<int> s;

    for(int i=0;i<n;i++){
        while(!s.empty() && temperatures[s.top()]<temperatures[i]){
            ans[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(temperatures);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}