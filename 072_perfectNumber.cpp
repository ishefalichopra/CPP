#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int fact(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return fact(n - 1) * n;
        }
    }

public:
    int perfectCheck(int n)
    {
        int temp = n;
        int sum = 0;
        while (n > 0)
        {
            int x = n % 10;
            int y = fact(x);
            sum = sum + y;
            n = n / 10;
        }
        if (sum == temp)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.perfectCheck(n) << endl;
    }

    return 0;
}