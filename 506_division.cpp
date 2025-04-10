#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    if(divisor == 0) return INT_MAX; // Handle division by zero
    if(dividend == INT_MIN && divisor == -1) return INT_MAX; // Handle overflow case

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1; // Determine the sign of the result
    long long absDividend = abs((long long)dividend); // Use long long to prevent overflow
    long long absDivisor = abs((long long)divisor);
    long long quotient = 0;

    while(absDividend >= absDivisor){
        absDividend -= absDivisor;
        quotient++;
    }

    return sign * quotient;
}

int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl; // Output the result of division
   

return 0;
}