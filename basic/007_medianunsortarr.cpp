#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int find_median(vector<int> v)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        return n % 2 == 0 ? (v[(n / 2) - 1] + v[n / 2]) / 2 : v[n / 2];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << "The median of the given array is:" << endl;
        Solution ob;
        int ans = ob.find_median(v);
        cout << ans;
    }
    return 0;
}