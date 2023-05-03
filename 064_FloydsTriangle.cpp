#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printFloydTriangle(int N)
    {
        // Write Your Code here
        int count=1;
        int i=1;
        while(i<=N){
            int j=1;
            while(j<=i){
                cout<<count<<" ";
                count++;
                j+=1;
            }
            cout<<endl;
            i+=1;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    Solution ob;
    ob.printFloydTriangle(n);
    cout<<endl;

return 0;
}