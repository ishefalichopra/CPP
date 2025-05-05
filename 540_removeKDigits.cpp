#include<bits/stdc++.h>
using namespace std;

string removeKDigits(string num, int k){
    stack<char>s;

    for(char c: num){
        while(!s.empty() && c < s.top() && k>0){
            s.pop();
            k--;
        }
        s.push(c);
    }

    while(k>0 && !s.empty()){
        s.pop();
        k--;
    }

    string ans = "";

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    int i=0;
    while(ans[0] == '0' && ans.size()>1)i++;
    ans = ans.substr(i);

    return ans.empty() ? "0" : ans;
}

int main()
{
    string num;
    cin>>num;

    int k;
    cin>>k;

    cout<<removeKDigits(num, k)<<endl;
    

return 0;
}