#include<bits/stdc++.h>
using namespace std;

 bool isPowerOfTwo(int n) {
        for (int i = 0; i < 32; i++) {
            if (n == pow(2, i))
                return true;
        }
        return false;
    }

int main()
{
    int n = 16;
    cout << isPowerOfTwo(n) << endl;

return 0;
}