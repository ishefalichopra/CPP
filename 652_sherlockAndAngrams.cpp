#include <bits/stdc++.h>
using namespace std;

int sherlockAndAnagrams(string s)
{
    int n = s.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            sort(temp.begin(), temp.end());
            mp[temp]++;
        }
    }

    int ans = 0;
    for (auto &it : mp)
    {
        if (it.second >= 2)
        {
            ans += (it.second * (it.second - 1)) / 2;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int result = sherlockAndAnagrams(s);
    cout << result << endl;

    return 0;
}