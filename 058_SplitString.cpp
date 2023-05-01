#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> SplitString(string S)
    {
        vector<string> ans;
        string S1 = "", S2 = "", S3 = "";
        for (int i = 0; i < S.length(); i++)
        {
            if (islower(S[i]) || isupper(S[i]))
            {
                S1 = S1 + S[i];
            }
            if (isdigit(S[i]))
            {
                S2 = S2 + S[i];
            }
            if (!islower(S[i]) && !isupper(S[i]) && !isdigit(S[i]))
            {
                S3 = S3 + S[i];
            }
        }
        ans.push_back(S1);
        ans.push_back(S2);
        ans.push_back(S3);
        return ans;
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
        vector<string> result = ob.SplitString(S);
        for (int i = 0; i < result.size(); ++i)
        {
            /* code */
            if (result[i] == " ")
            {
                cout << -1 << endl;
            }
            else
            {
                cout << result[i] << endl;
            }
        }
    }
    return 0;
}