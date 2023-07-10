#include <bits/stdc++.h>
using namespace std;
/*
     A
    ABA
   ABCBA
  ABCDCBA
*/
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c = 'A';
        for (int j = 0; j <= (n - i); j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i; k++)
        {
            cout << c;
            c++;
        }
        c--;
        for (int l = 1; l < i; l++)
        {
            c--;
            cout << c ;
        }
        cout << endl;
    }

    return 0;
}