#include <bits/stdc++.h>
using namespace std;
bool isbinary(string str);
bool isbinary(string str)
{
    bool flag;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 0 || str[i] == 0)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
}
int main()
{
    string str;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> str;
        cout << isbinary(str) << endl;
    }
    return 0;
}