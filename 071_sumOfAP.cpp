#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
		int sum_of_ap(int n,int a, int d)
		{
		    // Code here.
		    int sum = (n*(2*a+(n-1)*d))/2;
		    return sum;
		}
};
int main()
{
    int n,a,d;
    cin>>n>>a>>d;
    Solution ob;
    cout<<ob.sum_of_ap(n,a,d);
    cout<<endl;

return 0;
}