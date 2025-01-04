#include <bits/stdc++.h>
using namespace std;
void reverseInterger(int n)
{
    int rev = 0;

    while (n > 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    cout << rev << endl;
}

int main()
{
    int n;
    cin >> n;
    reverseInterger(n);

    return 0;
}