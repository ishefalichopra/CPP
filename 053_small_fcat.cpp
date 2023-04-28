#include<iostream>
using namespace std;
class Solution
{
	public:
		long long int find_fact(int n)
		{
		    // Code here.
		    long long ans=1;;
		    for(int i=1;i<=n;i++){
		        ans = ans * i;
		    }
		    return ans;
		}
};

int main()
{int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    Solution ob;
    int ans = ob.find_fact(n);
    cout<<ans<<endl;
}

return 0;
}
