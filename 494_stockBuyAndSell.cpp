#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0];
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < mini)
        {
            mini = prices[i];
        }
        else
        {
            profit = max(profit, prices[i] - mini);
        }
    }
    return profit;
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

    cout << maxProfit(prices) << endl;
    return 0;
}