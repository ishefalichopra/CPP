#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
        freq[t[i]]--;
    }

    for (auto &it : freq)
    {
        if (it.second != 0)
            return false;
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (isAnagram(s, t))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}