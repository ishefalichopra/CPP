#include<bits/stdc++.h>
using namespace std;

string largestPalindromic(string num) {
    string ans = "";
    map<char, int, greater<char>> mp;

    for (char c : num) {
        mp[c]++;
    }

    string left = "", middle = "", right = "";

    for (auto& [digit, count] : mp) {
        int pairs = count / 2;

        if (digit == '0' && left.empty()) continue;

        left += string(pairs, digit);

        if (count % 2 == 1 && middle.empty()) {
            middle = digit;
        }
    }

    right = left;
    reverse(right.begin(), right.end());

    ans = left + middle + right;

    if (ans.empty()) return "0";
    return ans;
}


int main()
{
    string num;
    cin >> num;

    string result = largestPalindromic(num);
    cout << result << endl;

return 0;
}