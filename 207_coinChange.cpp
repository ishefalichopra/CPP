#include<bits/stdc++.h>
using namespace std;

long long int count(int coins[], int n,int sum ){
    long long int table[sum+1];
    memset(table,0,sizeof(table));
    table[0] = 1;
    for(int i=0;i<n;++i){
        for(int j=coins[i];j<=sum;++j){
            table[j] += table[j-coins[i]];
        }
    }
    return table[sum];
}

int main()
{
    int n;
    cin >> n;
    int coins[n];
    for(int i=0;i<n;++i){
        cin >> coins[i];
    }
    int sum;
    cin >> sum;
    cout << count(coins,n,sum) << endl;

return 0;
}