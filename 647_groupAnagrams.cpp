#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp;

    for (string s : strs)
    {
        string st = s;
        sort(st.begin(), st.end());
        mp[st].push_back(s);
    }

    for (auto &[s, v] : mp)
    {
        result.push_back(v);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    vector<vector<string>> result = groupAnagrams(strs);

    for (const auto &group : result)
    {
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}