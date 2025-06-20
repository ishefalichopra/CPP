#include<bits/stdc++.h>
using namespace std;

string biggerIsGreater(string w){
    int n = w.size();
    int i = n-2;

    while(i>=0 && w[i]>=w[i+1])i--;

    int j = n-1;
    while(w[i] <= w[j])j--;

    swap(w[i], w[j]);
    reverse(w.begin()+i+1, w.end());
    return w;
}

int main()
{
    string w;
    cin>>w;

    cout<<biggerIsGreater(w)<<endl;

return 0;
}