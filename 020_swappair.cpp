#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> get(int a, int b)
    {
        pair<int, int> c;
        c.first = b;
        c.second = a;
        return c;
    }
};
int main()
{
    int a, b;
    cin >> a >> b;
    Solution obj;
    pair<int, int> p = obj.get(a, b);
    cout << p.first << ' ' << p.second << endl;

    return 0;
}