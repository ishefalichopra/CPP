#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getAreas(int L, int W, int B, int H, int R)
    {
        // code here
        vector<int> ans;
        int Rectangle = L * W;
        int Triangle = 0.5 * B * H;
        int Circle = 3.14 * R * R;
        ans.push_back(Rectangle);
        ans.push_back(Triangle);
        ans.push_back(Circle);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int L, W, B, H, R;
        cin>>L>>W>>B>>H>>R;
        Solution ob;
        vector<int> ans = ob.getAreas(L, W, B, H, R);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    return 0;
}