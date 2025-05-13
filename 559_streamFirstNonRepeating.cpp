#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void findFirstNonRepeating(string &s)
{
    queue<char> q;
    unordered_map<char, int> freq;
    string ans = "";

    for (char ch : s)
    {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }

        if (!q.empty())
        {
            ans += q.front();
        }
        else
        {
            ans += '#';
        }
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "First non-repeating character stream: ";
    cout<<findFirstNonRepeating(s)<<endl;
    return 0;
}