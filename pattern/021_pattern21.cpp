/*
****
 ***
  **
   *
*/
#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int i=1;

while(i<=n){
   int space = (i-1);
   while(space>0){
    cout<<" ";
    space-=1;
   }
    int j=1;
    while(j<=(n-i+1)){
        cout<<"*";
        j+=1;
    }
    cout<<endl;
    i+=1;
}
return 0;
}