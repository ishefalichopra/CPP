#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
int counta =0;
int countb=0;
while(a>0){
    if(a&1){
        counta++;
    }
    a = a>>1;
}
while(b>0){
    if(b&1){
        countb++;
    }
    b = b>>1;
}
int count = counta + countb;
cout<<count;
return 0;
}