#include <bits/stdc++.h>
using namespace std;

void printGfg(int N)
{
    // Code here
    if (N <= 0)
    {
        return;
    }
    cout << "GFG ";
    printGfg(N - 1);
}
int main()
{
    int N;
    cin >> N;
    printGfg(N);
}
