#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	
	bool fascinating(int n) {
	    // code here
	    int a = n*2;
	    int b = n*3;
	    string s1 = to_string(a);
	    string s2 = to_string(b);
	    string s3 = to_string(n);
	    
	    string s4 = s1+s2+s3;
	    
	    string s5 = "123456789";
	    sort(s4.begin(), s4.end());
	    if(s4 == s5)
	    {
	        return true;
	    }
	    else
	    return false;
	}
};
int main()
{int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    Solution ob;
    auto ans = ob.fascinating(n);
    if(ans){
        cout<<( "Facinating");
    }
    else {
 cout<<( "not Facinating");
    }
}


return 0;
}