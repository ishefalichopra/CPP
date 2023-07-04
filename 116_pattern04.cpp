#include<bits/stdc++.h>
using namespace std;
/*
**********
****  ****
***    ***
**      **
*        *
**      **
***    ***
****  ****
**********
*/
void pattern(int n){
for(int i=1;i<=n;i++){
    for(int j=1;j<=(n-i+1);j++){
        cout<<"*";
    }
    for(int k=2;k<=2*(i);k++){
        cout<<" ";
    }
    for(int l=1;l<=(n-i+1);l++){
        cout<<"*";
    }
    cout<<endl;
}
for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
        cout<<"*";
    }
    for(int k=2;k<=2*(n-i+1);k++){
        cout<<" ";
    }
    for(int l=1;l<=i;l++){
        cout<<"*";
    }
    cout<<endl;

}
}
int main()
{
int n;
cin>>n;
pattern(n);
return 0;
}