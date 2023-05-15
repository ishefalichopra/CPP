#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
int isFullPrime(int N){
    int digit;
    for(int i=2;i*i<=N;i++){
      if(N%i==0) return 0;
    }
    while(N){
       digit = N%10;
       if(digit!=2&&digit!=3&&digit!=5&&digit!=7)return 0;
       N=N/10;
    }
    return 1;  
}
};
int main()
{
int t;
cin>>t;
while(t--){
int N;
cin>>N;
Solution ob;
cout<<ob.isFullPrime(N)<<endl;
}
return 0;
}