#include <bits/stdc++.h>
using namespace std;

int bulbSwitch(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
        cnt++;
    return cnt;
}

int main()
{
    int n = 3; // Example input
    int result = bulbSwitch(n);
    cout<<result<<endl;

    return 0;
}