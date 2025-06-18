#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty())
        return 0;
    int n = s.size();
    int left = 0, right = 0;
    unordered_map<char, bool> mp;
    int maxCnt = 1;

    while (right < n)
    {
        while (mp[s[right]])
        {
            mp[s[left]] = false;
            left++;
        }
        mp[s[right]] = true;
        maxCnt = max(maxCnt, right - left + 1);
        right++;
    }
    return maxCnt;
}

int main()
{
    string s;
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << result << endl;

    return 0;
}