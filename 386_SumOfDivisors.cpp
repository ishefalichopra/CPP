#include<bits/stdc++.h>
using namespace std;

long long sumOfDivisors(int n){
     vector<long long> divisorSum(n + 1, 0);
     long long sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j += i){
                divisorSum[j] += i;
            }
        }
        for(int i = 1; i <= n; i++){
            sum += divisorSum[i];
        }
        return sum;

}

int main()
{
    int n;
    cin>>n;
    cout<<sumOfDivisors(n)<<endl;

return 0;
}