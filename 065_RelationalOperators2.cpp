#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void relationalOperators(int A,int B)
    {
        // Write Your Code here
        if(A>B) cout<<A<<" is greater than "<<B<<endl;
        if(A<B) cout<<A<<" is less than "<<B<<endl;
        if(A==B) cout<<A<<" is equals than "<<B<<endl;
    }
};

int main()
{
    int a,b;
    cin>>a>>b;
    Solution ob;
    ob.relationalOperators(a,b);
    cout<<endl;

return 0;
}