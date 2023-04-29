#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		long long int sum_of_square_oddNumbers(long long int n)
		{
		    // Code here.
		    return n*(2*n+1)*(2*n-1)/3;
		}
};

int main()
{int t;
cin>>t;
while(t--){
    long long int n;
    cin>>n;
    Solution ob;
    int ans = ob.sum_of_square_oddNumbers(n);
    cout<<ans<<endl;
}

return 0;
}