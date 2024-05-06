#include<bits/stdc++.h>
using namespace std;

string CommonPrefix(string arr[],int n){
    string s1=arr[0];
    string s2= arr[n-1];
    string res="";
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i]){
            res+=s1[i];
        }
        else
        break;
    }
    if(res=="") return "-1";
    else return res;
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << CommonPrefix(arr,n) << endl;

return 0;
}