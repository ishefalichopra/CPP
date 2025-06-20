#include <bits/stdc++.h>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> ans(n, 0);

    for (auto &v : bookings)
    {
        int a = v[0];
        int b = v[1];
        int k = v[2];
        ans[a - 1] += k;
        if (b < n)
            ans[b] -= k;
    }

    for (int i = 1; i < n; i++)
    {
        ans[i] += ans[i - 1];
    }

    return ans;
}

int main()
{
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;

    vector<int> result = corpFlightBookings(bookings, n);
    cout << "Flight bookings: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}