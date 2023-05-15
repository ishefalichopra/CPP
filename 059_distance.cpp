#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		int distance(int x1, int y1, int x2, int y2)
		       {  
		         
		       int lenght=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		       return round(sqrt (lenght));
		     
		       }	   
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        Solution ob;
        cout<<ob.distance(x1,y1,x2,y2)<<endl;
    }

return 0;
}