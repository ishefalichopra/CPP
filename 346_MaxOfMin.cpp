#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfMin(int arr[], int n){
    vector<int> left(n+1,-1);
    vector<int>right(n+1,n);

    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(!s.empty()){
            left[i]=s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(!s.empty()){
            right[i]=s.top();
        }
        s.push(i);
    }

    vector<int>ans(n+1,0);

    for(int i=0;i<n;i++){
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],arr[i]);
    }

    for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }

    vector<int>res(ans.begin()+1,ans.end());
    return res;
}

int main()
{
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>res=maxOfMin(arr,n);
    for(auto x:res){
        cout<<x<<" ";
    }

return 0;
}