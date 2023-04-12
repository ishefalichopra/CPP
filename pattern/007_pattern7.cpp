// 1
// 22
// 333
// 4444
#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int i=1;
while(i<=n){
    int j=1;
    while(j<=i){
        cout<<i;
        j+=1;
    }
    cout<<endl;
    i+=1;
}
return 0;
}