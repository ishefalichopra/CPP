#include<bits/stdc++.h>
using namespace std;

int calcXOR(int n){
    if(n%4 == 0) return n;
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    return 0;
}


int findXOR(int L, int R){
    return calcXOR(R) ^ calcXOR(L-1);
}

int main()
{
    int L, R;
    cin >> L >> R; // Input the range L and R
    cout << findXOR(L, R) << endl; // Output the XOR from L to R

return 0;
}