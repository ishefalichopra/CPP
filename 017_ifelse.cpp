#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string compareNM(int n, int m){
        // code here
        if(n<m){
            return "lesser";
        }
        if(n==m){
            return "equal";
        }
     if(n>m){
            return "greater";
        }
   return " "; }

};
int main()
{
    int n,m;
    cin>>n>>m;
    Solution obj;
    cout<<obj.compareNM(n,m);

return 0;
}