#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2)
        {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
    string num;
    cin >> num;

    string result = largestOddNumber(num);
    if (result.empty())
    {
        cout << "No odd number found" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}