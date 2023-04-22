#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
vector<int> count(string s){
    int arr[4]={0,0,0,0};
    for(int i=0;s[i]!='\0';i++){
        
        if(isupper(s[i])){
            arr[0]++;
        }
        else if(islower(s[i])){
            arr[1]++;
        }
        else if(isdigit(s[i])){
            arr[2]++;
        }
        else{
            arr[3]++;
        }


    }
    vector<int> R(arr,arr+3);
    return R;
}
};
int main()
{string s;
cin>>s;
Solution ob;
vector<int> res = ob.count(s);
for(int i:res)
cout<<i<<'\n';

return 0;
}