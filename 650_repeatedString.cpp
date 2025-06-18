#include <bits/stdc++.h>
using namespace std;

long counta(string s, int l, int r)
{
    long cnt = 0;
    while (l < r)
    {
        if (s[l] == 'a')
            cnt++;
        l++;
    }
    return cnt;
}

long repeatedString(string s, long n)
{
    if (s.size() == 1 && s[0] == 'a')
        return n;
    long ans = 0;
    long cnt = counta(s, 0, s.size());
    long x = n / s.size();
    ans = x * cnt;
    ans += counta(s, 0, n % s.size());

    return ans;
}

int main()
{
    string s;
    long n;
    cin >> s >> n;

    long result = repeatedString(s, n);
    cout << result << endl;

    return 0;
}