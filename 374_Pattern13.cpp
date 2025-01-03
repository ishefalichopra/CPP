#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int j, i;

    for (i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (j = 1; j <= i; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    return 0;
}