#include<bits/stdc++.h>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    vector<int>temp;
    //sortt(a,n);
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    temp.push_back(a[n-2]);
    temp.push_back(a[1]);
    
    return temp;
    
}
int main()
{
int n;
cin >> n;
vector<int> a(n);
for(int i = 0; i < n; i++)
cin >> a[i];
vector<int> ans = getSecondOrderElements(n, a);
for(int i = 0; i < ans.size(); i++)
cout << ans[i] << " ";

return 0;
}