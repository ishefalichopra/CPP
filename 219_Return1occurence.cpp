#include<bits/stdc++.h>
using namespace std;

 char nonrepeatingCharacter(string S)
    {
       //Your code here
        map<char,int> mp;

    for(int i=0; i<S.size(); i++) {
        mp[S[i]]++;
    }
    for(int i=0; i<S.size(); i++) {
        if(mp[S[i]] == 1) {
            return S[i];
        }
    }
    return '$'; // If no non-repeating character found
}

int main()
{
    string s;
    cin >> s;
    cout << nonrepeatingCharacter(s) << endl;


return 0;
}