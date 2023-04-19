#include<iostream>
using namespace std;
class Solution{
    public:
    void scores(long long a[], long long b[], int &ca, int &cb)
    {
        // Your code goes here   
       
        for(int i=0;i<3;i++){
            if(a[i]>b[i]){
                ca++;
            }
            if(a[i]<b[i]){
                cb++;
            }
            if(a[i]==b[i]){
                continue;
            }
            
        }
      
    }
};
int main()
{int t;
cin>>t;
while(t--){
    long long int  a[5], b[5], i=0;
    int ca=0, cb=0;
    for(int i=0; i<3;i++){
        cin>>a[i];
    }
    for(int i=0; i<3;i++){
        cin>>b[i];
    }
    Solution ob;
    ob.scores(a,b,ca,cb);
    cout<<ca<<" "<<cb;
}

return 0;
}