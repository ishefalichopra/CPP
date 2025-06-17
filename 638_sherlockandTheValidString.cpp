#include<bits/stdc++.h>
using namespace std;

string isValid(string s){
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    unordered_map<int, int> count;
    for (const auto& pair : freq) {
        count[pair.second]++;
    }

    if (count.size() == 1) {
        return "YES";
    }

    if (count.size() > 2) {
        return "NO";
    }

    auto it = count.begin();
    int first = it->first;
    int firstCount = it->second;
    it++;
    int second = it->first;
    int secondCount = it->second;

    if ((firstCount == 1 && (first - second == 1 || first == 1)) ||
        (secondCount == 1 && (second - first == 1 || second == 1))) {
        return "YES";
    }

    return "NO";
}

int main()
{
    string s;
    cin >> s;

    cout << isValid(s) << endl;

return 0;
}