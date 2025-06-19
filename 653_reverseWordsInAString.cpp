#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();
    int i = 0, l = 0, r = 0;

    reverse(s.begin(), s.end());

    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            break;
        r = i;
        while (i < n && s[i] != ' ')
            i++;
        reverse(s.begin() + r, s.begin() + i);
        if (l > 0)
        {
            s[l] = ' ';
            l++;
        }
        while (r < i)
        {
            s[l++] = s[r++];
        }
    }
    s.resize(l);
    return s;
}

int main()
{
    string s;
    getline(cin, s);

    cout << reverseWords(s) << endl;
    return 0;
}