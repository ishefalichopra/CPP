#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    string isVowel(char c){
        // code here 
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='E'||c=='U'){
            return "YES";
        }
        else{
            return "NO";
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        char c;
        cin>>c;
        Solution ob;
        cout<<ob.isVowel(c);
    }

return 0;
}