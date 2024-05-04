#include<bits/stdc++.h>
using namespace std;


string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalin(string S) {
    string maxS = "";

    for (int i = 0; i < S.size(); i++) {
        string odd = expandAroundCenter(S, i, i);       
        string even = expandAroundCenter(S, i, i + 1);  
        if (odd.size() > maxS.size()) maxS = odd;
        if (even.size() > maxS.size()) maxS = even;
    }

    return maxS;
}


int main()
{
    string s;
    cin >> s;
    cout << longestPalin(s) << endl;

return 0;
}