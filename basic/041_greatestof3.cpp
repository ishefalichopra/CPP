#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int greatestOfThree(int A, int B, int C) {
        // code here
        if((A>B)&&(A>C)){
            return A;
        }
         if((B>A)&&(B>C)){
          return B;
        }
         if((C>B)&&(C>A)){
           return C;
        }
    }
};
int main()
{int t;
cin>>t;
while(t--){
    int A,B,C;
    cin>>A>>B>>C;
    Solution ob;
    cout<<ob.greatestOfThree(A,B,C)<<endl;
}

return 0;
}