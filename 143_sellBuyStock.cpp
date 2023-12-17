#include<bits/stdc++.h>
using namespace std;
int bestTimeToBuyAndSellStock(vector<int>& prices) {
    if (prices.empty()) {
        return 0; // If no prices, no profit can be made.
    }

    int mini = prices[0]; // Initialize mini to the first price
    int maxi = 0; // Initialize maxi to zero

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < mini) {
            mini = prices[i]; // Update the minimum price encountered so far
        } else {
            // Calculate the potential profit using current price as selling price
            int potentialProfit = prices[i] - mini;
            if (potentialProfit > maxi) {
                maxi = potentialProfit; // Update the maximum profit if potentialProfit is higher
            }
        }
    }
    return maxi;
}

int main()
{
int n;
cin>>n;
vector<int> prices(n);
for(int i=0;i<n;i++)
{
cin>>prices[i];
}
cout<<bestTimeToBuyAndSellStock(prices)<<endl;
return 0;
}