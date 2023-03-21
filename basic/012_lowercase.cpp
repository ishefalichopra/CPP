#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    string toLower(string S) {
       transform(S.begin(), S.end(), S.begin(), ::tolower);
       return S;
    }
};

int main()
{
    int t;
    cin>>t;
    while (t)
    {
        /* code */
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.toLower(S)<<endl;
    }
    return 0;
}