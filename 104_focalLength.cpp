#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int findFocalLength(float R, string type){
	    //Code here
	    if(type =="convex"){
	        return floor(-R/2);
	    }
	    if(type == "concave"){
	        return floor(R/2);
	    }
	}
};
int main()
{

    float R;
    cin>>R;
    string type;
    cin>>type;
    Solution obj;
    cout<<obj.findFocalLength(R,type)<<endl;
    

return 0;
}