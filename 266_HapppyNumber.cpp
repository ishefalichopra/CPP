#include<bits/stdc++.h>
using namespace std;

bool isHappyI(int n){

    int sum;
    do{
        sum=0;
        while(n>0){
            int curr= n%10;
            sum+= curr*curr;
            n/=10;
        }
        n = sum;
    }while(n!=1&&n!=4);
    return n==1;
}

int main()
{
    int n = 19;
    cout << isHappyI(n) << endl;

return 0;
}