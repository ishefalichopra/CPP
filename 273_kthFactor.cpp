#include<bits/stdc++.h>
using namespace std;

int kthFactor(int n, int k){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            k--;
            if(k==0)
            return i;
        }
    }
    return -1;
}


int main()
{
    cout<<kthFactor(12,3)<<endl;

return 0;
}