#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	vector<long long int> find(int l, int b, int h)
	{
	    // Code here
	    
	  vector<long long int> ans;
	   
	  long long int  surfaceArea = (2.0*l*b + 2.0*b*h + 2.0*l*h);
	  long long int  Volume = 1.0*l*b*h;
	    
	  ans.push_back(surfaceArea);
	  ans.push_back(Volume);
	  
	  return ans;
	    
	}  
};

int main()
{   
    int t;
    cin>>t;
    while(t--){
    int l,b,h;
    cin>>l>>b>>h;
    Solution ob;
    vector<long long int>ans = ob.find(l,b,h);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;}

return 0;
}