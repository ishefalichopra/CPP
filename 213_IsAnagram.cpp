#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b){
    if(a.size()!=b.size()){
        return false;
    }
    map<char,int>mpA, mpB;
    for(int i=0;i<a.size();i++){
        mpA[a[i]]++;
    }
    for(int j=0;j<b.size();j++){
        mpB[b[j]]++;
    }
    return mpA==mpB;
}

int main()
{
    string a,b;
    cin >> a >> b;
    cout << isAnagram(a,b) << endl;

return 0;
}