#include<iostream>
using namespace std;
class Solution
{
	public:
		long sum_of_ap(long n,long a, long d)
		{
		    long sum=(n*(2*a+(n-1)*d))/2;
		    return sum;
		}
};
int main()
{
long n,a,d;
cin>>n>>a>>d;
Solution ob;
cout<<ob.sum_of_ap(n,a,d)<<endl;
return 0;
}