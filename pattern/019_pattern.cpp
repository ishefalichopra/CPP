/*
 *
 **
 ***
 ****
 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int i = 1;
    
    while (i <= n)
    {
        int space = n - i;
        int j = 1;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }
        while (j <= i)
        {
            cout << "*";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    return 0;
}