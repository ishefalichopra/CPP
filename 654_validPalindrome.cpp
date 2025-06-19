#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();
    if (n == 1)
        return true;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (!isalnum(s[l]))
        {
            l++;
            continue;
        }
        if (!isalnum(s[r]))
        {
            r--;
            continue;
        }
        if (tolower(s[l]) != tolower(s[r]))
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);

    cout<<isPalindrome(s)<<endl;

    return 0;
}