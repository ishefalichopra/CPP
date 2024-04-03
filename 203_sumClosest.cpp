#include<bits/stdc++.h>
using namespace std;

vector<int> sumClosest(vector<int>arr, int x){
    vector<int>ans;
    int i=0;
    int j= arr.size()-1;
    int e1,e2;
    int currmin= INT_MAX;

    sort(arr.begin(), arr.end());

    while(i<j){
        int sum = arr[i]+arr[j];
        if(abs(sum-x)<currmin){
            currmin = abs(sum-x);
            e1 = arr[i];
            e2 = arr[j];
        }
        if(sum>x){
            j--;
        }
        else{
            i++;
        }
    }
    ans.push_back(e1);
    ans.push_back(e2);
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
    int x;
    cin >> x;
    vector<int>res = sumClosest(a,x);
    for(int i=0;i<res.size();++i){
        cout << res[i] << " ";
    }
    cout << endl;

return 0;
}