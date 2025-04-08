#include<bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k) {
    // Your code here
    int mask = 1<<k;
    return n&mask;
}

int main()
{
    int n, k;
    cin >> n >> k;
    if (checkKthBit(n, k)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    

return 0;
}