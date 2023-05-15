#include <bits/stdc++.h>
using namespace std;

vector<string> extractIntegerWords(string s)
{
    vector<string> v;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            ans += s[i];
        }
        else
        {
            if (ans != "")
            {
                v.push_back(ans);
                ans = "";
            }
        }
    }
    if (ans != "")
    {
        v.push_back(ans);
    }
    if (v.size() == 0)
    {
        v.push_back("No Integers");
    }

    return v;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        vector<string> ans = extractIntegerWords(str);
        for (auto i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
