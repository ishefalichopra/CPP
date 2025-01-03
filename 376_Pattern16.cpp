#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int i,j;

    for(i=1;i<n;i++){
        char ch = 'A';
        for(j=1;j<=(n-i);j++){
            cout<<" ";
        }
        for(j=1;j<=i;j++){
            cout<<ch;
            ch++;
        }
        ch-=2;
        for(j=1;j<i;j++){
            cout<<ch;
            ch--;
        }
        cout<<endl;
    }

return 0;
}