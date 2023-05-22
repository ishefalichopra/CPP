#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

int mulClock( int n1, int n2 ) {
    return n1 * n2 % 12;
} // T: 0.02 - 0.03

};
int main()
{
int n1,n2;
cin>>n1>>n2;
Solution obj;
cout<<obj.mulClock(n1,n2);

return 0;
}