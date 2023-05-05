#include<bits/stdc++.h>
using namespace std;


string convert(string s)
{
    // code here.
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&& s[i]<='z')
            s[i]='z'-s[i]+'a';
        else
        s[i]='Z'-s[i]+'A';
    }
    return s;
}
int main()
{int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    string ans = convert (s);
    cout<<ans<<endl;
}

return 0;
}