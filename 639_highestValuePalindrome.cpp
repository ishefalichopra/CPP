#include <bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k)
{
    vector<bool> changed(n, false);

    int l = 0, r = n - 1;

    // Step 1: Make it a palindrome
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (k == 0)
                return "-1";
            char bigger = max(s[l], s[r]);
            s[l] = s[r] = bigger;
            changed[l] = changed[r] = true;
            k--;
        }
        l++;
        r--;
    }

    // Step 2: Maximize digits to '9'
    l = 0, r = n - 1;
    while (l <= r)
    {
        if (l == r)
        {
            if (k > 0 && s[l] != '9')
            {
                s[l] = '9';
                k--;
            }
        }

        if (s[l] != '9')
        {
            if (changed[l] || changed[r])
            {
                if (k >= 1)
                {
                    s[l] = s[r] = '9';
                    k--;
                }
            }
            else if (k >= 2)
            {
                s[l] = s[r] = '9';
                k -= 2;
            }
        }
        l++;
        r--;
    }

    return s;
}

int main()
{
    string s;
    int n, k;
    cin >> s >> n >> k;
    string result = highestValuePalindrome(s, n, k);
    cout << result << endl;

    return 0;
}