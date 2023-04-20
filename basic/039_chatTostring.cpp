#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string chartostr(char arr[] , int n)
    {
        //code here
        string str="";
        for(int i=0;i<n;i++){
            str += arr[i];
        }
        return str;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[n];
        }
        Solution ob;
        cout<<ob.chartostr(arr,n)<<endl;
    }

return 0;
}