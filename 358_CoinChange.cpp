#include<bits/stdc++.h>
using namespace std;

int coinChangeRecursive(vector<int>& coins, int amount, vector<int>& dp){
    if(amount == 0) return 0;
    if(amount < 0) return -1;
    if(dp[amount] != 0) return dp[amount];
    int minCoins = INT_MAX;
    for(int coin : coins){
        int res = coinChangeRecursive(coins, amount - coin, dp);
        if(res >= 0 && res < minCoins){
            minCoins = 1 + res;
        }
    }
    dp[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
    return dp[amount];
}

int coinChangeMemoization(vector<int>& coins, int amount){
    vector<int> dp(amount+1, INT_MAX);
    dp[0]=0;

    for(int i=1;i<=amount;i++){
        for(int coin : coins){
            if(i-coin >= 0 && dp[i-coin] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }

    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int coinChangeTabulation(vector<int>& coins, int amount){
    vector<int> dp(amount+1, INT_MAX);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for(int coin : coins){
            if(i-coin >= 0 && dp[i-coin] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}


int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    vector<int> dp(amount + 1, 0);
    cout << coinChangeTabulation(coins, amount) << endl;

return 0;
}