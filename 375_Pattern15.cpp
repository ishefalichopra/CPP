#include<bits/stdc++.h>
using namespace std;
int main()
{
int n = 5;
    int j, i;
    

    for (i = 1; i <= n; i++)
    {   char ch = 'A'+i-1;
        for (j = 1; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}