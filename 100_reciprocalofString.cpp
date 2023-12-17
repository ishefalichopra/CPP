#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reciprocalString(string s)
    {
        // Write Your code here
        int i,l=s.length(),num;
        for(i=0;i<l;i++){
            if('a' <= s[i] && s[i] <= 'z'){
                num = s[i] - 'a';
                s[i] = 'z' - num;
            }
            else if ('A' <= s[i] && s[i] <= 'Z'){
                num = s[i] - 'A';
                s[i] = 'Z' - num;
            } 
        }
        return s;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.reciprocalString(s);

return 0;
}