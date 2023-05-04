#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string triDownwards(string S)
    {
        // code here
        for (int i = 0; i < S.length() - 1; i++)
        {
            cout << S << endl;
            S[i] = '.';
        }
        return S;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        string ans = ob.triDownwards(S);

        for (int i = 0; i < S.length(); i++)
        {

            cout << ans[i];
            if ((i + 1) % S.length() == 0)
                cout << endl;
        }
    }
    return 0;
}