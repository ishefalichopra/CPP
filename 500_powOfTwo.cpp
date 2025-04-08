#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;
    return (n & (n-1)) == 0 ? true : false;
}

int main()
{
    int n;
    cin >> n;
    if (isPowerOfTwo(n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

return 0;
}