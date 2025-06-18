#include <bits/stdc++.h>
using namespace std;

int maxPower(string s)
{
    int cnt = 1, maxCnt = 1;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main()
{
    string s;
    cin >> s;
    cout << maxPower(s) << endl;
    return 0;
}