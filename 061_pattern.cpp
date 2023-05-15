#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void printPattern(int N)
    {
        // Write Your Code here
        int i=1;
        while(i<=N){
            int j=1;
            while(j<=i){
                cout<<"*";
                j+=1;
            }
            cout<<" ";
            i+=1;
        }
    }
};
int main()
{
    int N;
    cin>>N;
    Solution ob;
   ob.printPattern(N);
   cout<<endl;

return 0;
}