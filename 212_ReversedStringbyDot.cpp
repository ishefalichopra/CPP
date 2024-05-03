#include<bits/stdc++.h>
using namespace std;




string reverseWords(string S) {
    string temp = "";
    string reversedString = "";
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != '.') {
            temp += S[i];
        } else {
            reversedString = temp + (reversedString.empty() ? "" : ".") + reversedString;
            temp = "";
        }
    }
    reversedString = temp + (reversedString.empty() ? "" : ".") + reversedString; 
    return reversedString;
}

int main()
{


    string s;
    cin >> s;
    cout << reverseWords(s) << endl;

return 0;
}