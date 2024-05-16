#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<longestSubstrDistinctChars(s)<<endl;
    }
}// } Driver Code Ends


int longestSubstrDistinctChars (string S)

{
    unordered_map <char, bool> m;

    int res = 1, i = 0, j = 0, n = S.length ();

    while (j < n)
    {
        // extending the right pointer till a point all characters are distinct
        while (j < n and !m[S[j]])
        {
            m[S[j]] = true;
            j++;
        }
        
        // updating result if we get a longer length than the existing result
        res = max (res, j - i);
        if (j == n) break;
    
        
        // removing the repeated character by moving the left pointer
        while (i < n and S[i] != S[j])
        {
            m[S[i]] = false;
            i++;
        }
        i++;
        j++;
    }
    return res;
}

