#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;

    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            cout<<"*";
        }
        for(int j=(2*(n-i));j>=1;j--){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            cout<<"*";
        }
        for(int j=1;j<=(2*(n-i));j++){
            cout<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<"*";
        }
        cout<<endl;
    }

return 0;
}