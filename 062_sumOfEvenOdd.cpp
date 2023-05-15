#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> find_sum(int n)
    {
        // Code here
        vector<int> v;
        int i, sumodd = 0, sumeven = 0;
        for (i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                sumeven = sumeven + i;
            }
            else
            {
                sumodd = sumodd + i;
            }
        }
        v.push_back(sumodd);
        v.push_back(sumeven);
        return v;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution ob;
    vector<int> ans = ob.find_sum(n);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}