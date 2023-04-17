#include<bits/stdc++.h>
using namespace std;
class Solution{
public:	
		
	string removeVowels(string S) 
	{
	    // Your code goes here
	    string str="";
	    for(int i=0; i<S.length(); i++)
	    {
            if(S[i]=='a' ||S[i]=='e' ||S[i]=='i' ||S[i]=='o' ||S[i]=='u')
                continue;
            else
                str += S[i];
	    }
	    return str;
	}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--){
        string S,ch;
        getline(cin,S);
        Solution ob;
        cout<<ob.removeVowels(S)<<endl;
    }

return 0;
}