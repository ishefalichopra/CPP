// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1
#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int i=1;
while(i<=n){
    int j=1;
    while(j<=n-i+1){
        cout<<j;
        j+=1;
    }
    int k=1;
    while(k<=i){
        cout<<"**";
        k+=1;
    }
    int count=n-i+1;
    while(count>0){
        cout<<count;
        count-=1;
    }
    cout<<endl;
    i+=1;
}
return 0;
}