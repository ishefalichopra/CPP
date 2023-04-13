// D
// CD 
// BCD 
// ABCD
#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int i=1;
while(i<=n){
    int j=1;
    char ch= 'A'+n-i;
    while(j<=i){
        cout<<ch;
        ch+=1;
        j+=1;

    }
    cout<<endl;
    i+=1;
}
return 0;
}