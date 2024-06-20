#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &s, vector<int> &t)
{
    bool allPresent = true;
    for (int i = 0; i < 256; i++)
    {
        if (t[i] > s[i])
        {
            allPresent = false;
            break;
        }
    }
    return allPresent;
}

string minWindow(string s, string t)
{
    if (t.size() > s.size())
        return "";

    vector<int> tCount(256, 0);
    vector<int> sCount(256, 0);

    for (int i = 0; i < t.size(); i++)
    {
        tCount[t[i]]++;
    }

    int st = 0, ed = 0;
    string ans = "";

    while (st <= ed && ed < s.size())
    {
        sCount[s[ed]]++;

        while (st <= ed && sCount[s[st]] >= tCount[s[st]])
        {
            string temp = s.substr(st, ed - st + 1);
            if (check(sCount, tCount) &&
                (ans.size() > temp.size() || ans == ""))
            {
                ans = temp;
            }

            if (sCount[s[st]] == tCount[s[st]])
                break;
            sCount[s[st]]--;
            st++;
        }
        ed++;
    }
    return ans;
}

int main()
{ 
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    

    return 0;
}