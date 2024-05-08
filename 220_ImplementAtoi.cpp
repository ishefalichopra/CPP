#include<bits/stdc++.h>
using namespace std;

bool isNumericChar(char x){
    return (x>='0' && x<='9')?true:false;
}

int atoi(string s){
    int n=s.size();

    int res=0;
    int sign=1;
    int i=0;

    if(s[0]=='-'){
        sign=-1;
        i++;
    }

    for(;i<n;i++){
        if(isNumericChar(s[i])==false){
            return -1;
        }
        res = res * 10 + (s[i] - '0');
    }

    return sign*res;
}

int main()
{
    string s;
    cin >> s;
    cout << atoi(s) << endl;

return 0;
}