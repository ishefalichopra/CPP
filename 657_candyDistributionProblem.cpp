#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i - 1] < ratings[i])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i + 1] < ratings[i])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += candies[i];
    }
    return ans;
}

int main()
{
    vector<int> ratings = {1, 0, 2};
    int result = candy(ratings);
    cout << "Minimum candies required: " << result << endl;

    return 0;
}