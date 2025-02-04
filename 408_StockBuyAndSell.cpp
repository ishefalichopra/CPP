#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);
        maxProfit = max(maxProfit, prices[i] - mini);
    }
    return maxProfit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices);

    return 0;
}