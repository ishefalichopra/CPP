#include<iostream>
using namespace std;
class Solution{   
public:
    string compareNum(int A,int B){
        // code here 
        if(A>B){
            cout<<A<<" is greater than "<<B;        }
            if (A<B){
                cout<<A<<" is less than "<<B; 
            }
            if(A==B){
                cout<<A<<" is equals to "<<B;
            }
            return " ";
    }
    
};
int main()
{int t;
cin>>t;
while(t--){
    int A,B;
    cin>>A>>B;
    Solution ob;
    
    cout<<ob.compareNum(A,B)<<endl;
}

return 0;
}