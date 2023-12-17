#include <bits/stdc++.h>
using namespace std;
/*
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/
void printSquare(int n)
{
    for (int i = 1-n; i < n; i++)
    {
        for (int j = 1-n; j < n; j++)
        {
            if (abs(i > abs(j)))
            {
                cout << abs(i) + 1;
            }
            else
            {
                cout << abs(j) + 1;
            }
        }

        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    printSquare(n);

    return 0;
}