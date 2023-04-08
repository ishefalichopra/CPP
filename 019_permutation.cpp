#include<bits/stdc++.h>
using namespace std;

    class Solution{
public:
  long long Factorial(int n)

    {

        long long fact=1;

        

        for(int i=1; i<=n; i++)

        {

            fact=fact*i;

        }

        return fact;

    }

    

    long long nPr(int n, int r)

    {

        long long numerator = Factorial(n);

        long long denominator = Factorial(n-r);

        

        return numerator/denominator;

    }

 

};

int main()
{int n,r;
cin>>n>>r;
Solution ob;
cout<<ob.nPr(n,r)<<endl;


return 0;
}