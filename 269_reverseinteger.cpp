
#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    long long int rev = 0; // Initialize rev to 0

    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;

        // Check for overflow before updating rev
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > 7))
        {
            return 0;
        }
        if (rev < (INT_MIN / 10) || (rev == (INT_MIN / 10) && digit < -8))
        {
            return 0;
        }

        rev = rev * 10 + digit;
    }

    return (int)rev;
}

int main()
{
    int x = 123;
    cout << reverse(x) << endl;

    return 0;
}