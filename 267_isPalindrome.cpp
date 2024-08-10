#include<bits/stdc++.h>
using namespace std;

 int reverse(int x) {
        int ans = 0;
        
        while (x > 0) {
            // Check for potential overflow before multiplying by 10
            if (ans > (INT_MAX - x % 10) / 10) {
                return 0; // Return 0 or another error value to indicate
                          // overflow
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    bool isPalindrome(int x) { return x == reverse(x); }

int main()
{
    int x = 121;
    cout << isPalindrome(x) << endl;

return 0;
}