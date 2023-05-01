#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
		long sum_of_gp(long n,long a, long r)
		{
		    // Code here
		    long ans = a*(pow(r,n)-1)/(r-1);
		    if(r==1)return a*n;
		   else return ans;
		}
};

int main()
{int t;
    cin>>t;
    while(t--){
        int a,n,r;
        cin>>a>>n>>r;
        Solution ob;
        cout<<ob.sum_of_gp(a,n,r)<<endl;
    }

return 0;
}