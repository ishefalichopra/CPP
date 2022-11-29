#include <iostream>
using namespace std;
void printPat(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = n-i+1; k > 0; k--)
            {
                cout << n - j + 1 << " ";
            }
        }
        cout << "$";
    }
}
int main()
{
    int n;
    cin >> n;
    printPat(n);
    return 0;
}