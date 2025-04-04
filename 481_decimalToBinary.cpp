#include<bits/stdc++.h>
using namespace std;

void decimalToBInary(int n){
    if(n==0){
        cout<<0<<endl;
        return;
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n<0){
        cout<<"Negative number"<<endl;
        return;
    }
    int binary[32];
    int i=0;

    while(n>0){
        binary[i] = n%2;
        n /= 2;
        i++;
    }
    for(int j = i-1;j>=0;j--){
        cout<<binary[j];
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    cout<<"Decimal to Binary of "<<n<<": ";
    decimalToBInary(n);

return 0;
}