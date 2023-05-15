#include<iostream>
using namespace std;
class Solution

{

 public:

 int count_divisors(int n)

 {

     //Code here.

     int count=0;

     for(int i=1;i*i<=n;i++){

         if((n%i==0)&&(i%3==0))
         
         count++;//12

         if(i==(n/i))break;

         if(n%(n/i)==0&&((n/i)%3==0))
         
         count++;

     }

     return count;

 }

};
int main()
{int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    Solution ob;
    int ans = ob.count_divisors(n);
    cout<<ans<<endl;
}

return 0;
}