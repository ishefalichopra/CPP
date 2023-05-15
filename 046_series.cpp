#include<iostream>
using namespace std;
class Solution {
  public:
    int findNthTerm(int N) {
        // code here
        return N*(N+1)/2;
    }
};
int main()
{int N;
cin>>N;
Solution ob;
cout<<ob.findNthTerm(N)<<endl;

return 0;
}