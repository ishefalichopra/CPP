#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    for(int i=n;i>=1;i-=2){
        for(int j=1;j<=i;j+=2){
            cout<<"*";
        }
        for(int j=1;j<=((n-i));j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j+=2){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=i;j+=2){
            cout<<"*";
        }
        for(int j=1;j<((n-i));j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j+=2){
            cout<<"*";
        }
        cout<<endl;
    }

return 0;
}