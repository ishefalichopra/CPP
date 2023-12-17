#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> v)
{ int n = v.size();
    vector<int> ls;
    map< int, int> mpp;
    int mini = (int)(n / 3) + 1;
    
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans = majorityElement(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}