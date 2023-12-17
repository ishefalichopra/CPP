#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	int find(vector<int>A, vector<int>B){
	
	int a=A[0] * B[0] + A[1] * B[1] + A[2] * B[2];
	 int b=(A[1]*B[2]-A[2]*B[1])-(A[0]*B[2]-A[2]*B[0])+(A[0]*B[1]-A[1]*B[0]);
	    int c=abs(a);
	    int d=abs(pow(b,2));
	    if(c==0){
	        return 2;
	    }
	    else if(d==0){
	        return 1;
	    }
	    else{
	        return 0;
	    
    	}
	}
};
int main()
{
    vector<int> A(3),B(3);
    for(int i=0;i<3;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>B[i];
    }
    Solution obj;
    cout<<obj.find(A,B);

return 0;
}