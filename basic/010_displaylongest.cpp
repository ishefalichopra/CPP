#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longest(string names[], int n)
    {
        string s = "";
        int i = 0;
        while (i < n)
        {
            if (names[i].size() > s.size())
            {
                s = names[i];
            }
            i++;
        }
        return s;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string names[n];
        for (int i = 0; i < n; i++)
        {
            /* code */
            cin>>names[i];

        }
        Solution ob;
        cout<<ob.longest(names,n)<<endl;
        
    }

    return 0;
}