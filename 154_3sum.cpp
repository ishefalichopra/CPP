#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(int n, vector<int> &num)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && num[i] == num[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = num[i] + num[j] + num[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && num[j] == num[j - 1])
                    j++;
                while (j < k && num[k] == num[k - 1])
                    k--;
            }
        }
    }
    return ans;
}
int main()
{
  int n;
  cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> ans = triplet(n,v);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
    cout << endl;
    

    return 0;
}