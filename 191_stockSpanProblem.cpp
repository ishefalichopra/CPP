#include<bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[],int n){
    stack<int>st;
    vector<int>res(n,1);
    st.push(0);
    for(int i=1;i<n;++i){
        while(!st.empty()&&price[st.top()]<=price[i]){
            res[i]+=res[st.top()];
            st.pop(); 
    }
    st.push(i);
    }
    return res;
}


int main()
{
    int n;
    cin >> n;
    int price[n];
    for(int i=0;i<n;++i){
        cin >> price[i];
    }
    vector<int>res=calculateSpan(price,n);
    for(int i=0;i<n;++i){
        cout << res[i] << " ";
    }
    cout << endl;

return 0;
}