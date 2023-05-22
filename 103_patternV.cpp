#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> numberPattern(int N)
    {
        // Write Your Code here
        vector<string>ans;
        for(int i=1;i<N+1;i++){
            string s="";
            for (int j=1;j<=i;j++){
                s+=to_string(j);
            }
            for(int k=i-1;k>=1;k--){
                  s+=to_string(k);
            //    ans.push_back(s);
           }
            
           ans.push_back(s);
            
        }
        return ans;
    }
};
int main()
{
    int N;
    cin>>N;
    Solution obj;
    vector<string>ans=obj.numberPattern(N);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

return 0;
}