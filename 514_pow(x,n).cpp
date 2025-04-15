#include<bits/stdc++.h>
using namespace std;


double myPow(double x, int n) {
    if(n == 0){
        return 1;
    }

    if(n<0){
        if(n == INT_MIN){
           return 1/(myPow(x,-(n+1))*x); 
        }
         x = 1/x;
         n = -n;
    }

    double half = myPow(x,n/2);
    return (n%2) ? half*half*x : half*half;
}

int main()
{
    double x;
    int n;
    cin >> x >> n; // Input the base and exponent
    double result = myPow(x, n);
    cout << "The result of " << x << "^" << n << " is: " << result << endl; // Output the result

return 0;
}