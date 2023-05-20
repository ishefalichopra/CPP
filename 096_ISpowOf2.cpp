#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 32; i++)
    {
        if (n != pow(2, i))
        {
            cout << "No";
        }
    }
    cout << "Yes";
    return 0;
}